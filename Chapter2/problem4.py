#!/usr/bin/python3

from numpy import random

#********************************************************
# Find the min and max elements from N elements using
# no more than 3N/2 -1 comparisons
#********************************************************

def find_min_max(elements_list):

    # Split N elements into groups of 2
    # Take first pair, compare, set min and max
    # For each subsequent pair, compare the two numbers,
    # then take min and max and compare to the current min and max

    current_min = float('inf')
    current_max = -float('inf')

    for i in range(1, int(len(elements_list)/2)):
        
        if elements_list[2*i] > elements_list[2*i+1]:
            tmin = elements_list[2*i+1]
            tmax = elements_list[2*i]
        else:
            tmin = elements_list[2*i]
            tmax = elements_list[2*i+1]

        if (tmin < current_min):
            current_min = tmin
        if (tmax > current_max):
            current_max = tmax
            

    return current_min, current_max

# Test functions

mylist = 100*(random.sample(10) - 0.5)
print(mylist)
print(find_min_max(mylist))

