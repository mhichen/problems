#include<iostream>
#include<map>
#include<vector>
#include<stdexcept>  

class Solution
{
  
public:
  std::vector<int> TwoSum(std::vector<int> nums, int target)
  {

    // array to be returned indicating location of two numbers
    std::vector<int>indices;

    // hash table of the integers in nums
    std::map<int, int> hashmap;

    // Loop over array of numbers, nums
    for (int i = 0; i < nums.size(); i++)
    {
      int x = nums[i];
      
      // Check if the second number (target - x) is in hash table
      std::map<int, int>::iterator it = hashmap.find(target - x);

      //If (target - x) was found, save to indices array
      if (it != hashmap.end())
      {
	indices.push_back(it->second);
	indices.push_back(i); //
	return indices;
      }

      // If this point is reached, means that (target-x) was not found
      // So x should be added to the hashtable
      hashmap[x] = i;

    }

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
  tnum.push_back(6);
  tnum.push_back(8);
  tnum.push_back(4);
  Solution tsol;
  std::vector<int> solution = tsol.TwoSum(tnum, target);

  for (std::vector<int>::const_iterator i = solution.begin(); i != solution.end(); ++i)
  {
    std::cout << *i << "\n";
  }
}
  
