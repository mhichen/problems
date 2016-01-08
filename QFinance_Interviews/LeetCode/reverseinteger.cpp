#include<iostream>
#include<deque>

class Solution
{

public:

  // Reverses an integer
  // (ex) 123 becomes 321
  int ReverseInteger(int num)
  {

    int result = 0;

    while (num != 0){
      if (num > 214748364){
	return result;
      }

      result = result * 10 + num%10;

      num /= 10;
      
    }

    return result;
  }


};


int main()
{

  int number = 123;

  Solution sol;
  
  int reversed = sol.ReverseInteger(number);

  std::cout << "Input is " << number << "\n";
  std::cout << "Reversed is " << reversed << "\n";

}
