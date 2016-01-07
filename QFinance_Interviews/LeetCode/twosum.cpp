#include<iostream>
#include<map>
#include<vector>
  

class Solution
{
  
public:
  std::vector<int> TwoSum(std::vector<int> nums, int target)
  {

    std::vector<int> indices;
    std::map<int, int> hashmap;// = new std::map<int, int>;

    for (int i = 0; i < nums.size(); i++)
    {
      //std::cout << nums[i] << "\n";
      int x = nums[i];

      std::map<int, int>::iterator it = hashmap.find(target - x);
      
      if (it != hashmap.end()){
	indices.push_back(it->second + 1);
	indices.push_back(i + 1);
	return indices;
      }
      hashmap[x] =  i;

    }

    return indices;
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
  
