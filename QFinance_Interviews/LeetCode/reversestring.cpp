#include<iostream>
#include<map>
#include<vector>
  

class Solution
{
public:


  /**
   * Given a string s, reverses the string word by word
   */
  std::string reverse_string(std::string input)
  {
    std::string reversed;

    // j keeps track of index of end of word
    int j = input.length();

    // i keeps track of index of beginning of word
    for (int i = input.length() - 1; i >= 0; i--)
    {
      // if trailing spaces, then reset j index
      if (input[i] == ' ')
      {
	j = i;
      } // otherwise, if the character preceding i is a space
      // then we have found the start of a word, so we add a space
      // to the reversed string, then add the word itself
      else if (i == 0 || input[i-1] == ' ')
      {
	if (reversed.length() != 0)
	{
	  reversed.append(" ");
	}
	reversed.append(input.substr(i, j-i));
      }
      
    }
    

    return reversed;
  }
  
  
};
  

// *******************************************************
int main()
{
  Solution tsol;

  std::string input = "  the sky is blue   ";

  std::cout << input << "\n";
  std::cout << tsol.reverse_string(input) << "\n";
 
}

  
