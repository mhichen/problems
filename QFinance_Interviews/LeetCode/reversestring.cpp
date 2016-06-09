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

    // Start at end of the input string and index backwards
    // When the beginning of a word is reached, then the word
    // is stored into the output string
    
    // Index keeping track of end of word
    int j = input.length();

    // Index keeping track of beginning of word
    for (int i = input.length() - 1; i>= 0; i--)
    {

      // check for trailing spaces
      if (input[i] == ' ')
      {
	j = i; // reset the end of word to be where index i is
      }
      // otherwise, either already reached the very beginning of the
      // string OR at the beginning of a word (verified by checking to
      // see if the previous (i-1) char is a space)
      else if (i == 0 || input[i-1] == ' ')
      {
	// Add a space if there have already been words added to the
	// result string
	if (reversed.length() != 0)
	{
	  reversed.append(" ");
	}
	// tack on the word
	reversed.append(input.substr(i, j-i));
      }

      // If the index i is in the middle of a word, everything
      // in this block is simply skipped and
      
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

  
