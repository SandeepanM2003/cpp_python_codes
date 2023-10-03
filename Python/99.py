#!/usr/bin/env python3
"""
Problem:
Given an unsorted array of integers, find the length of the longest consecutive
elements sequence.
For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is
[1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.

Solution:
Time complexity: O(n)
Space complexity: O(n)
"""

from typing import List

# lces = Longest consecutive elements sequence
def lces(arr: List[int]) -> int:
    unique_elements = set(arr)
    longest_sequence = 0
    # generating the longest sequence length
    for i in range(len(arr)):
        if (arr[i] - 1) not in unique_elements:
            # current element is the starting element of a sequence
            j = arr[i]
            while j in unique_elements:
                j += 1
            # update longest sequence length
            longest_sequence = max(longest_sequence, j - arr[i])
    return longest_sequence


if __name__ == "__main__":
    # test input/outputs
    print(lces([100, 4, 200, 1]))
    print(lces([100, 4, 200, 1, 3]))
    print(lces([100, 4, 200, 2, 3]))
    print(lces([100, 4, 200, 1, 3, 2]))
    print(lces([100, 4, 200, 1, 3, 2, 5]))
