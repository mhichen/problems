#!/usr/bin/python3

#********************************************************
# Given sorted array A and an integer S, returns true
# if there are a pair of indices, i and j, such that
# A[i] + A[j] = S (where i and j aren't necessarily
# distinct)
#********************************************************

def contains_sum_equal_to(S, array):

    # Make a dictionary out of the array
    new_list = set(array)

    # Loop over the dictionary
    # If
    for i in new_list:
        if ( (S - i) in new_list ):
            return True

    return False



if __name__ == "__main__":

    myarray = [0, 2, 4, 5, 10, 12, 16, 19]

    print(contains_sum_equal_to(11, myarray))
