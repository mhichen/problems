#!/usr/bin/python3

def is_palindrome(x):

    # For case of negative number
    if (x < 0):
        return False

    # Use divisor to get left-most digit
    divisor = 1

    while (x // divisor >= 10):
        divisor *= 10
        
    while x != 0:
        
        if (x // divisor) != (x % 10):
            return False
        x = (x % divisor) // 10

        divisor /= 100 # Increment divisor by 100 since lopped off 2 digis

    return True

    ## This (incomplete) approach takes up extra space
    # num = str(x)
    
    # mid_ind = len(num) // 2
    
    # for i in range(mid_ind, -1, -1):
    #     if num[mid_ind - i] != num[mid_ind + i]:
    #         return False

    # return True

        
    
if __name__ == "__main__":
    
    number = 1235323
    print(is_palindrome(number))
