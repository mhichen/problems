#!/usr/bin/python3

#****************************************************
# Given an array of sorted, distinct integers, find
# index i such that A[i] = i
# This is a modification of problem 2, where instead
# of looking for k in A, we're looking for the case
# where A[k] - k = 0.
#****************************************************

def find_index_equivalent(array):
    
    upper_bound = len(array)-1
    lower_bound = 0

    # if everything is equal to or less than k
    if (array[upper_bound] <= upper_bound):
        return -1
    
    while (upper_bound > (lower_bound + 1)):

        mid = int((lower_bound + upper_bound)/2)

        #print(lower_bound, upper_bound)

        # then search bottom half
        if (array[mid] >= mid):
            upper_bound = mid
        else:
            lower_bound = mid


    if (array[lower_bound] == lower_bound):
        return lower_bound
    elif (array[upper_bound] == upper_bound):
        return upper_bound
    

if __name__ == "__main__":
    
    myarray = [-1, 0, 2, 4, 6, 9, 10, 11, 14, 17, 23]
    print(find_index_equivalent(myarray))
