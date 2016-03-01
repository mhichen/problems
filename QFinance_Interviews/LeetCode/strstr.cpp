#include<iostream>
#include<map>
#include<vector>
  

class Solution
{
public:


  /**
   * Brute force method
   */
  int strstr(std::string needle, std::string haystack)
  {

    // This indexes haystack
    for (int i = 0; ; i++)
    {
      // This indexes needle
      for (int j = 0; ; j++)
      {
	// reached the end of segment matching needle
	if (j == needle.length() )
	{
	  return i;
	}

	// needle's length is greater than haystack's length
	if ( (i + j) == haystack.length() )
	{
	  return -1;
	}

	// restart needle index if mismatched character
	if (needle[j] != haystack[i+j])
	{
	  break;
	}
	
      }
	
    }
    
  }
  
};
  

// *******************************************************
int main()
{
  Solution tsol;
  
  std::string needle = "";
  std::string haystack = "";    
  std::cout << tsol.strstr(needle, haystack) << "\n";

  needle = "issi";
  haystack = "mississippi";
  std::cout << tsol.strstr(needle, haystack) << "\n";

}

  
