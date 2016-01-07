#!/usr/bin/python3

def plusOne(digits):
    """
    :type digits: List[int]
    :rtype: List[int]
    """

    for ind in range(len(digits)-1, -1, -1):
        
        if digits[ind] < 9:
            digits[ind] += 1
            return
        else:
            digits[ind] = 0

    # For special case of all digits being 9 
    digits.append(0)
    digits[0] = 1

    
if __name__ == "__main__":
    
    nums = [9, 9]
    plusOne(nums)
    print(nums)
