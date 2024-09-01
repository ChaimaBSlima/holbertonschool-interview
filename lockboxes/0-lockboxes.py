#!/usr/bin/python3
"""
[C#22] Interview Preparation - Algorithms
Lockboxes
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be unlocked.

    Args:
        boxes (list of list of int): A list where each element is
        a list containing the keys available in that particular box.
        The index of the outer list represents the box number.

    Returns:
        bool: True if all boxes can be unlocked, False otherwise.

    Note:
      - the print comment '#' are for debbegging the code.
    """

    n = len(boxes)
    box_closed = [False] * n
    box_closed[0] = True
    keys = boxes[0]
    for key in keys:
        if key < n and not box_closed[key]:
            box_closed[key] = True
            keys.extend(boxes[key])
    return (not (False in box_closed))
