#!/usr/bin/python3

# *****************************************************
# Takes an integer and returns another integer that is
# the floor of the square root of the input
# *****************************************************

def floor_of_square_root_of(in_num):

    # Set the upper bound as input, lower bound
    # as 0; Set midpoint as halfway between the
    # upper and lower bound.
    # If the square of the midpoint is greater
    # than the input, then set as new upper bound.
    # If square of midpoint is less than the input,
    # set as the new lower bound; set a new midpoint
    # This cycle breaks when the midpoint == lower bound

    upper_bound = in_num
    lower_bound = 0

    midpoint = int((lower_bound + upper_bound)/2)

    to_continue = True

    while (to_continue):


        if ( (midpoint * midpoint) > in_num ):
            upper_bound = midpoint;

        if ( (midpoint * midpoint) < in_num ):
            lower_bound = midpoint

        midpoint = int((lower_bound + upper_bound)/2)

        
        # Conditions to break the while loop    
        if ( (midpoint * midpoint) == in_num):
            to_continue = False

        if (midpoint == lower_bound):
            to_continue = False

    return midpoint


# Test the function
print("The answer is ", floor_of_square_root_of(78))
