#!/usr/bin/python3

# *****************************************************
# Takes a sorted array A of integers and a key and
# returns the index of the first appearance of k
# in A.  
# Function returns -1 if k doesn't appear in A
# *****************************************************


def binary_search(array, k):

    size = len(array)

    # keeps track of where we are in the index
    index = 0;

    while (index < size):

        # find the middle of the current portion of list
        mid = round(index + (size-1 - index)/2)

        # if the value is less than k, increase index
        if (array[mid] < k):
            index = mid + 1

        elif (array[mid] == k):
            # checks to see if the previous
            # entry also holds the same value
            # and continues as such since we
            # are looking for the first appearance
            # in the list
            while (array[mid-1] == k):
                mid = mid -1
            return mid

        else:
            index = mid - 1
    return -1


# Test the binary search function

A = [1, 2, 3, 3, 3, 4, 4, 4, 5, 6]

print(binary_search(A,3))
print(binary_search(A,4))
print(binary_search(A,7))
