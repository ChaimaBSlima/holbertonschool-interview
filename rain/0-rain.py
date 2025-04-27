#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """
    Calculate the amount of rainwater retained after it rains.
    :param walls: List of integers representing wall heights.
    :return: Integer representing the amount of rainwater retained.
    """
    if not walls:
        return 0

    n = len(walls)
    water = 0

    left = 0
    right = n - 1
    left_max = 0
    right_max = 0

    while left < right:
        if walls[left] < walls[right]:
            if walls[left] >= left_max:
                left_max = walls[left]
            else:
                water += left_max - walls[left]
            left += 1
        else:
            if walls[right] >= right_max:
                right_max = walls[right]
            else:
                water += right_max - walls[right]
            right -= 1
    return water
