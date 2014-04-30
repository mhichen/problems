#!/usr/bin/python3

#********************************************
# Given a list of integers that are all paired
# except for one, find the unpaired one
#********************************************

def find_unpaired(numbers):
    
    sum = 0
    
    for i in numbers:
        
        sum ^= i
        
    return sum

# Test function
if __name__ == "__main__":
    
    list_of_ints = [0, 4, 2, 0, 3, 2, 4]
    
    print(find_unpaired(list_of_ints))
    