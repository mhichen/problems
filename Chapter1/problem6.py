#!/usr/bin/python3

import numpy as np
from numpy import random

#****************************************
# Given 300 million social security
# numbers, find a 9 digit number that is
# not in the file.  There is unlimited disk
# space but only 2 MB of RAM.
#****************************************

def hi16(n):
    return ((n & 0xffff0000) >> 16)

def lo16(n):
    return (n & 0x0000ffff)


def find_social_security(A):

    tarray = [0]*(2**16)

    # loop through A
    for val in A:
        tarray[hi16(val)] += 1

    # loop through tarray, find desired hi16
    for ind, val in enumerate(tarray):
        if val < 2**16:
            hi16result = ind
            break

    # null tarray
    tarray = [0]*(2**16)

    # loop through A
    for val in A:
        if (hi16(val) == hi16result):
            tarray[lo16(val)] = 1

    # loop through tarray, find desired low16
    for ind, val in enumerate(tarray):
        if val == 0:
            lo16result = ind
            break

    # assemble results
    return ( (hi16result << 16) + lo16result )
   

            
if __name__ == "__main__":

    A = (random.randint(0, 10**9-1, 3*10**6))
    A.astype(np.int32)

    A = [0,1,2,3,4,5, 6, 7, 8, 10]
    
    print("The following number is not found", find_social_security(A))
