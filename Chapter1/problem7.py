#!/usr/bin/python3

from problem2 import binary_search

#********************************************************
# Given two sorted lists, A and B, returns a new list C
# that is the intersection of the two.
#********************************************************

# This is for when the lists are approximately the same
def get_intersection(A, B):

    # Need two markers to keep track of where we are in
    # both lists.
    a_index = 0;
    b_index = 0;

    C = [];
    
    # Compare values of two lists, if one is less than the other,
    # advance the marker of the list with the smaller value
    while ( (a_index < len(A)) and (b_index < len(B)) ):


        if (A[a_index] < B[b_index]):
            a_index = a_index + 1
        elif (A[a_index] > B[b_index]):
            b_index = b_index + 1
        
        else:
            if ( (len(C) == 0) or (A[a_index] > C[-1])):
                C.append(A[a_index])
            a_index = a_index + 1
            b_index = b_index + 1
    

# This is for when one list is significantly larger than the other
def get_intersection_long(A,B):

    C = [];
    
    if (len(A) > len(B)):
        for b in B:
            # binary search returns index
            if (binary_search(A,b) != -1):
                C.append(b)

    else:
        for a in A:
            if (binary_search(B,a) != -1):
                C.append(a)
                

if __name__ == "__main__":
    
    A = [0, 1, 2, 3, 7, 10, 13, 29, 60, 71, 88, 99, 115, 123]
    B = [4, 5, 6, 7, 8, 9, 10, 12, 13, 29]
    print(get_intersection(A,B))
    print(get_intersection_long(A,B))
