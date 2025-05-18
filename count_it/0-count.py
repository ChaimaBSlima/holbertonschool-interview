#!/usr/bin/python3
import requests
import re


def count_words(subreddit, word_list, after=None, counts={}):
    headers = {'User-Agent': 'Mozilla/5.0'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'limit': 100}
    if after:
        params['after'] = after

    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    posts = data.get('children', [])

    # Normalize word list to lowercase and combine duplicates
    if not counts:
        for word in word_list:
            word_lower = word.lower()
            counts[word_lower] = counts.get(word_lower, 0)

    for post in posts:
        title = post['data']['title']
        # Extract words using regex that avoids trailing punctuation
        words_in_title = re.findall(r'\b\w+\b', title.lower())
        for word in words_in_title:
            if word in counts:
                counts[word] += 1

    # Recursive call if more posts are available
    after = data.get('after')
    if after:
        return count_words(subreddit, word_list, after, counts)

    # Print results once all data is processed
    sorted_counts = sorted(
        [(word, count) for word, count in counts.items() if count > 0],
        key=lambda x: (-x[1], x[0])
    )
    for word, count in sorted_counts:
        print(f"{word}: {count}")
