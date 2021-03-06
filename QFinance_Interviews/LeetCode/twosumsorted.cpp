#include<iostream>
#include<map>
#include<vector>
  

class Solution
{
  
public:
  /**
   * This takes n*log(n) to run
   */
  std::vector<int> TwoSum(std::vector<int> nums, int target)
  {

    // Loop over numbers in array and perform binary search for target - nums[i]
    for (int i = 0; i < nums.size(); i++){
      int j = binarysearch(nums, target - nums[i], i+1);

      if (j != -1)
      {
	return std::vector<int> {i, j};
      }
      
    }
  };


  /**
   * This method uses two indices
   */
  std::vector<int> TwoSum2(std::vector<int> nums, int target)
  {
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
      int sum = nums[i] + nums[j];
      // Case 1: If sum > target
      if (sum > target)
      {
	j --;
      }
      else if (sum < target) // Case 2: If sum < target
      {
	i++;
      }
      else // Case 3: If sum == target
      {
	return std::vector<int> {i,j};
      }
      
    }
    
  };

private:
  int binarysearch(std::vector<int> nums, int key, int start)
  {
    // Indices starting from left and right of array
    int Lind = start;
    int Rind = nums.size() - 1;

    while (Lind < Rind)
    {
      // middle index
      int Mind = (Lind + Rind)/2;

      // If this is true, the value is in the right side of array
      // so increment left index
      if (nums[Mind] < key)
      {
	Lind = Mind + 1;
      }
      // Otherwise, the value is in the left side of the array
      // so decrement right index
      else{
	Rind = Mind; // This includes case of nums[M] == key
      }
      
    } // End while

    // If left and right indices match up, and the value actually
    // matches key, then return L.  Otherwise return -1
    return ( (Lind == Rind) && (nums[Lind] == key) ) ? Lind : -1;
  }
  
};

// *******************************************************
int main()
{
  std::vector<int> tnum = {1, 3, 4, 6, 8};
  int target = 10;
  Solution tsol;
  std::vector<int> solution = tsol.TwoSum2(tnum, target);

  std::cout << "Indices of the two integers are \n";
  
  for (std::vector<int>::const_iterator i = solution.begin(); i != solution.end(); ++i)
  {
    std::cout << *i << "\n";
  }
}

  
