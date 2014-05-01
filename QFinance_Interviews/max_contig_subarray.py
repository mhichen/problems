#!/usr/bin/python3

#***********************************************
# Given an array, find the contiguous subarray
# that gives the largest sum.
#***********************************************

def max_contig_subarray(numbers):
    
    min = 0
    result = 0
    sum = 0
    
    for ind, val in enumerate(numbers):

        sum += val
        
        if sum < min:
            min = sum
           
        new_result = sum - min
        
        if new_result > result:
            result = new_result
            
    return result

if __name__ == "__main__":
    
    
    numbers = [1, 2, -7, 8, 3, 2, -1, 7, 2, -5]
    print(max_contig_subarray(numbers))