#!/usr/bin/python3

# *****************************************************
# Takes a sorted array A of integers and a key and
# returns the index of the first appearance of k
# in A.  
# Function returns -1 if k doesn't appear in A
# *****************************************************


def binary_search(array, k):

    upper_bound = len(array)-1
    lower_bound = 0

    # if everything is equal to or less than k
    if (array[upper_bound] <= k):
        return -1
    
    while (upper_bound > (lower_bound + 1)):

        mid = int((lower_bound + upper_bound)/2)

        #print(lower_bound, upper_bound)

        # then search bottom half
        if (array[mid] >= k):
            upper_bound = mid
        else:
            lower_bound = mid


    if (array[lower_bound] == k):
        return lower_bound
    elif (array[upper_bound] == k):
        return upper_bound
    else:
        return -1

# Test the binary search function
if __name__ == "__main__":
    A = [1, 2, 3, 3, 3, 4, 4, 4, 5, 6]

    print(binary_search(A,3))
    print(binary_search(A,4))
    print(binary_search(A,7))
