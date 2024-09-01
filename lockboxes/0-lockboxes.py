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
    keys = []
    i = 0
    while i < n:
        print(i)
        for j in range(len(boxes[i])):
            if boxes[i][j] not in keys:
                keys.append(boxes[i][j])
        print (keys)
        if i > 0 and i in keys:
            for k in keys:
                if k < n:
                    box_closed[k] = True
            print("closed box   ",box_closed )
        i += 1
    return (not(False in box_closed))
                
"""    keys = []
    used_keys = []
    i = 0
    test = True
    while i < n and test is True:
        for j in range(len(boxes[i])):
            if boxes[i][j] not in keys:
                keys.append(boxes[i][j])
        #print("\n",i)
        # print(keys)
        if i >= 1:
            if i not in keys:
                test = False
            else:
                if i not in used_keys:
                    for k in keys:
                        # print(k, end=",")
                        if k > i+1:
                            # print("\n K>i :",i+1,"<",k)
                            if k not in used_keys:
                                for k1 in range(len(boxes[k])):
                                    if boxes[k][k1] not in keys:
                                        keys.append(boxes[k][k1])
                            if k not in used_keys:
                                used_keys.append(k)
            # print("Used keys are  ", used_keys)

        i += 1
    return test
"""
