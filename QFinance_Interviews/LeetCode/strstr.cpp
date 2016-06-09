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
    // Index haystack
    for (int i = 0; ; i++)
    {
      // Index needle
      for (int j = 0; ; j++)
      {
	// Reach this point if the full needle has been matched
	// in the previous iteration over j so all that needs
	// to be done is returning the starting index in the
	// haystack
	if (j == needle.length())
	{
	  return i;
	}

	// If at any point, the sum of the indices
	// is greater than the length of the haystack,
	// then the needle is now longer than the (remaining)
	// haystack
	if (i + j == haystack.length())
	{
	  return -1;
	}

	// Starts over the needle (j) index if mismatch found
	if (haystack[i+j] != needle[j]){
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

  
