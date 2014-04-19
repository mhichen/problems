#!/usr/bin/python3

#*****************************************
# Given an nxm matrix, check if the number
# k is in the matrix.  The matrix is ordered
# such that the numbers increase across
# columns and across rows. 
#*****************************************

def find_in_matrix(k, mat):

    maxrow = len(mat)
    maxcol = len(mat[0])

    # i indexes row, j indexes column
    i = maxrow-1
    j = 0

    while True:

        while mat[i][j] > k: # move up a row

            i -= 1

            if i < 0:
                return False

        if mat[i][j] == k:
            return True

        while mat[i][j] < k: # move in a column

            j += 1

            if j > maxcol-1:
                return False

        if mat[i][j] == k:
            return True



if __name__ == "__main__":


    mat = [[0, 2, 5, 9],
           [1, 4, 6, 10],
           [4, 6, 7, 11],
           [5, 7, 9, 15]]

    print(find_in_matrix(12, mat))
    print(find_in_matrix(11, mat))
