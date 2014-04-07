#!/usr/bin/python3

#***************************************************
# Search sorted array for element that is one element
# larger than the given
#***************************************************

def get_one_larger(array, k):


    upper_bound = len(array)-1
    lower_bound = 0

    # if everything is equal to or less than k
    if (array[upper_bound] <= k):
        return -1
    
    while (upper_bound > (lower_bound + 1)):

        mid = int((lower_bound + upper_bound)/2)

        #print(lower_bound, upper_bound)

        # then search bottom half
        if (array[mid] > k):
            upper_bound = mid
        else:
            lower_bound = mid


    if (array[lower_bound] <= k):
        return upper_bound
    else:
        return lower_bound
    

# Test function
if __name__ == "__main__":
    
    myarray = [0, 4, 6, 7, 9, 10]

    print(get_one_larger(myarray, 4))
