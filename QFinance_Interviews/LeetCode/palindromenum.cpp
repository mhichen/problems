#include<iostream>
#include<map>
#include<vector>
  

class Solution
{
public:
  bool isPalindromeNum(int num)
  {
    // take care of case where num is negative
    if (num < 0)
    {
      return false;
    }

    // This allows us to get the left most digit
    int div = 1;
    while ( (num / div) >= 10 )
    {
      div *= 10;
    }
    
    int rdigi, ldigi;
    // Getting and chopping last digit
    while (num > 0)
    {
      rdigi = num%10;
      ldigi = num/div;

      if (rdigi != ldigi)
      {
	return false;
      }
      num = (num % div) / 10;
      // std::cout << rdigi << "\n";
      // std::cout << ldigi << "\n";
      // std::cout << num << "\n";

      // Need to divide by 100 instead of 10
      // because got rid of 2 digits
      div /= 100;

    }
    

    
    return true;
  }
};
  

// *******************************************************
int main()
{
  Solution tsol;

  int number = 1234321;
  std::cout << number << " ";
  
  if (tsol.isPalindromeNum(number))
  {
    std::cout << "is a palindrome\n";
  }
  else
  {
    std::cout << "is not a palindrome \n";
  }
  
  number = 123432;
  std::cout << number << " ";

  if (tsol.isPalindromeNum(number))
  {
    std::cout << "is a palindrome\n";
  }
  else
  {
    std::cout << "is not a palindrome \n";
  }
}

  
