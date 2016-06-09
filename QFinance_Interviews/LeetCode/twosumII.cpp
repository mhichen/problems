#include<iostream>
#include<map>
#include<vector>
#include<stdexcept>  

class Solution
{
  
public:
  std::vector<int> TwoSumII(std::vector<int> nums, int target)
  {

    // array to be returned indicating location of two numbers
    std::vector<int>indices;

    // Use the fact that input array is already sorted
    // Have two indices, i and j, at beginning and end of array, respectively
    // Scenario 1: nums(i) + nums(j) > target -> decrement j
    // Scenario 2: nums(i) + nums(j) == target -> solution found
    // Scenario 3: nums(i) + nums(j) < target -> increment i

    int i = 0;
    int j = nums.size()-1;
    int sum = 0;
    
    while (i < j)
    {
      sum = nums[i] + nums[j];

      // Scenario 1 -- decrement j
      if (sum > target)
      {
	j--;
      }
      // Scenario 3 -- increment i
      else if (sum < target)
      {
	i++;
      }
      // Scenario 2 -- found solution
      else if (sum == target)
      {
	indices.push_back(i);
	indices.push_back(j);
	return indices;
      }
    } // End while

    // Only reach this point if couldn't find solution
    throw std::invalid_argument("No two sum solution");
  }
      
};

// *******************************************************
int main()
{
  std::vector<int> tnum;
  int target = 5;
  tnum.push_back(1);
  tnum.push_back(3);
  tnum.push_back(4);
  tnum.push_back(6);
  tnum.push_back(8);
  Solution tsol;
  std::vector<int> solution = tsol.TwoSumII(tnum, target);

  for (std::vector<int>::const_iterator i = solution.begin(); i != solution.end(); ++i)
  {
    std::cout << *i << "\n";
  }
}
  
