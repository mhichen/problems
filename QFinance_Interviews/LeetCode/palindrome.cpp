#include<iostream>
#include<map>
#include<vector>
  

class Solution
{
public:
  bool isPalindrome(std::string str)
  {
    // keep track of 2 indices
    int i = 0;
    int j = str.length() - 1;

    while (i < j)
    {
      while ( i < j && !isalnum(str[i]) )
      {
	i++;
      }
      while ( i < j && !isalnum(str[j]) )
      {
	j--;
      }
      

      if ( tolower(str[i]) != tolower(str[j]) )
      {
	return false;
      }

      i++;
      j--;
    }
    
    return true;
  }
    
};
  

// *******************************************************
int main()
{
  Solution tsol;
  //"A man, a plan, a canal: Panama"
  if (tsol.isPalindrome("race a car"))
  {
    std::cout << "Is palindrome\n";
  }
  else
  {
    std::cout << "Is not palindrome \n";
  }
}

  
