#include<iostream>
#include<deque>

class Solution
{

public:

  // Reverses an integer
  // (ex) 123 becomes 321
  int ReverseInteger(int num)
  {

    int result;
    
    // Get sign of number
    int sign = 1;
    if (num < 0)
    {
      sign = -1;
      num = -num;
    }
    
    std::deque<int> tdeq;

    while(num > 0)
    {
      tdeq.push_back(num%10);
      num = num/10;
      std::cout << num << "\n";
    }

    std::cout << "\n";
    
    result = tdeq.front();
    tdeq.pop_front();
    
    while (!tdeq.empty())
    {
      result = result * 10 + tdeq.front();
      std::cout << result << "\n";
      tdeq.pop_front();
    }
    
    result *= sign;
    return result;
  }


};


int main()
{

  int number = -100;

  Solution sol;
  
  int reversed = sol.ReverseInteger(number);

  std::cout << "Input is " << number << "\n";
  std::cout << "Reversed is " << reversed << "\n";

}
