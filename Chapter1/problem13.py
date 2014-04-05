#!/usr/bin/python3

#******************************************
# Given a robot of mass m that uses energy
# when ascending and charges its battery
# when descending, how would you determine
# the minimum battery capacity required to
# complete a given trajectory
#******************************************

def battery_capacity(path):

    # For the simplest case, then minimum
    # required is the max - min, which is
    # an overestimation

    # Instead, we find the capacity where
    # the difference between two heights
    # is the greatest.  

    capacity = 0
    minimum = path[0]
    
    iteration = enumerate(path)
    next(iteration)
    
    for ind, val in iteration:
        
        if (val - minimum) > capacity:
            capacity = val - minimum

        if (minimum > val):
            minimum = val
        
    return capacity

if __name__ == "__main__":

    trajectory1 = [2, 4, 1, 6, 3, 7, 9, 1]
    trajectory2 = [7, 6, 5, 4, 3, 2, 1]
    trajectory3 = [1, 2, 3, 4, 5, 6, 9]
    
    print(battery_capacity(trajectory1))
    print(battery_capacity(trajectory2))
    print(battery_capacity(trajectory3))


