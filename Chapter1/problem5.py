#!/usr/bin/python3

#******************************************************
# Given array of unknown length, find first appearance
# of k in array A, return -1 if k is not in A
#******************************************************

def try_catch(array, k):
    try:
        return array[k]
    except:
        return float("inf")



def find(array, k):

    lower_bound = 0
    # Find upper bound by doubling the last upper bound
    upper_bound = 1

    while (try_catch(array, upper_bound) < float("inf")):
        upper_bound = upper_bound * 2

    while (upper_bound > (lower_bound + 1)):

        mid = int((lower_bound + upper_bound)/2)

        # then search bottom half
        if (try_catch(array, mid) >= k):
            upper_bound = mid
        else:
            lower_bound = mid

    if (try_catch(array, lower_bound) == k):
        return lower_bound
    elif (try_catch(array, upper_bound) == k):
        return upper_bound
    else:
        return -1



# Test function
myarray = [0, 5, 6, 10, 33, 55, 72, 120]

print(find(myarray, 1000))
