#!/usr/bin/python3

import numpy as np

#************************************************
# Rotate a square matrix by 90 degrees
#************************************************

def rotate_matrix(M):

    print(M)

    n = M.shape[1]

    for i in range(0, int(n/2)):
        for j in range(0, int((n+1)/2)):

            (M[i, j], M[j, n-1-i], M[n-1-i, n-1-j], M[n-1-j, i]) = (M[n-1-j, i], M[i, j], M[j, n-1-i], M[n-1-i, n-1-j])

    return M

# Test function
print(rotate_matrix(np.matrix('1, 2, 3, 4; 5, 6, 7, 8; 9, 10, 11, 12; 13, 14, 15, 16')))
print(rotate_matrix(np.matrix('1, 2, 3; 4, 5, 6; 7, 8, 9')))
