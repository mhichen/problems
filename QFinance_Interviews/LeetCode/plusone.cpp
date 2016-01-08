#include<iostream>
#include<vector>

class Solution
{

public:
  std::vector<int> PlusOne(std::vector<int> num)
  {

    for (int i = (num.size()-1); i >= 0; i--)
    {
      
      if (num[i] < 9)
      {
	num[i] += 1;
	return num;
      }
      else
      {
	num[i] = 0;
      }

    }

    //For special case of all digits being 9
    num.push_back(0);
    num[0] = 1;

    return num;
  }

};


int main()
{
  std::vector<int> num;
  num.push_back(9);
  num.push_back(9);

  Solution sol;
  
  std::vector<int> addedone = sol.PlusOne(num);

  std::cout << "Adding 1 to ";
  for (std::vector<int>::const_iterator i = num.begin(); i != num.end(); i++)
  {
    std::cout << *i;
  }
  std::cout << "\n";
  
  for (std::vector<int>::const_iterator i = addedone.begin(); i != addedone.end(); i++)
  {
    std::cout << *i;
  }
  std::cout << "\n";

}
