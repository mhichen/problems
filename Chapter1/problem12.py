#!/usr/bin/python3

import numpy as np
from numpy import random
from numpy import ndarray

#*****************************************************
# Given an array A of integers, find an integer k that
# is not present in A.  Assume integers are 32-bit
# signed integers
#*****************************************************

def find_missing_element(A):
    
    # Make an array R that is (size(A)+1) long
    # Traverse through A, apply mod(A) and set
    # R[A%size(R)] = 1
    # Traverse R, return position of first value
    # that is 0

    R = [0]*(len(A)+1)
    
    for i in A:
        R[i%len(R)] = 1

    for i, j in enumerate(R):
        if j == 0:
            return i
        
if __name__ == "__main__":

    A = [0, 1, 3, 4, 8, 11, 23, 55]
    print("The list is:", A)
    print("This element is not in the list:", find_missing_element(A))

    
