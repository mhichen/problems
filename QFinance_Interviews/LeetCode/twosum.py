#!/usr/bin/python3

# This has O(n^2) runtime, O(1) space
def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
        
    result = []
        
    for i, ival in enumerate(nums):
        for j in range(i+1, len(nums)):
        
            if ival + nums[j] == target:
                result.append(i+1)
                result.append(j+1)
                    
                return result
        

# This has O(n) runtime, O(n) space
def twoSumhash(nums, target):

    htable = {}

    for ind, i in enumerate(nums):
        print(htable)
        print(i)
        # if i in htable:
        #     print(htable[i])

        # print(target - i)
        if ((target - i) in htable):
            print('hello ')

            return [htable[target - i] + 1, ind + 1]

        else:
            htable[i] = ind


def twoSumsorted(nums, target):

    pass
    
if __name__ == "__main__":
    
    nums = [3, 2, 4]
    print(twoSumhash(nums, 6))
