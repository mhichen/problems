#include<iostream>
#include<map>
#include<vector>
  

class TwoSum
{

private:
  // Internal data structure
  std::map<int, int> hashmap;
  std::map<int, int>::iterator it;  
public:

  // Add an input to the internal data structure
  void add (int input);

  // Find a pair of numbers whose sum equals value
  bool find (int value);

  // Accesses a particular value in the internal data structure
  int get(int input);







  
  // /**
  //  * Add number input to internal hash table
  //  */
  // void add (int input)
  // {
  //   std::map<int, int>::iterator it = hashmap.find(input);
  //   int count = (it != hashmap.end()) ? it->second : 0;
  //   hashmap[input] = count+1;
  // };

  // /**
  //  * Find if there is a pair of numbers where the sum equals value
  //  */
  // bool find(int value)
  // {

    
    
  // };

}; // End of class declaration


// Accessor of an element in the internal data structure
int TwoSum::get(int input)
{
  it = hashmap.find(input);
  if (it != hashmap.end())
  {
    return it->second;
  }

  throw std::invalid_argument("Not found in hash table!");

}


// Add an input to the internal data structure
void TwoSum::add (int input)
{
  it = hashmap.find(input);

  // If the input is not found in the hashmap
  if (it == hashmap.end())
  {
    hashmap[input] = 1;
  }
  else
  {
    it->second += 1;
  }
  
}

bool TwoSum::find (int value)
{
  int num;
  std::map<int, int>::iterator tint;
  
  for (it = hashmap.begin(); it != hashmap.end(); it++)
  {
    num = value - it->first;
    // std::cout << "value is " << value << "\n";
    // std::cout << "it->first is " << it->first << "\n";
    // std::cout << "num is " << num << "\n\n\n";

    tint = hashmap.find(num);

    if (tint != hashmap.end())
    {
      // Take care of case with duplicate entries
      if ( (num == it->first) && (it->second >= 2) )
      {
	return true;
      }
      else
      {
	continue;
      }

      return true;
      
    }
    
  }

  return false;
	 
  
}














// public:
//   /**
//    * This takes n*log(n) to run
//    */
//   std::vector<int> TwoSum(std::vector<int> nums, int target)
//   {

//     // Loop over numbers in array and perform binary search for target - nums[i]
//     for (int i = 0; i < nums.size(); i++){
//       int j = binarysearch(nums, target - nums[i], i+1);

//       if (j != -1)
//       {
// 	return std::vector<int> {i, j};
//       }
      
//     }
//   };


//   /**
//    * This method uses two indices
//    */
//   std::vector<int> TwoSum2(std::vector<int> nums, int target)
//   {
//     int i = 0;
//     int j = nums.size() - 1;

//     while (i < j)
//     {
//       int sum = nums[i] + nums[j];
//       // Case 1: If sum > target
//       if (sum > target)
//       {
// 	j --;
//       }
//       else if (sum < target) // Case 2: If sum < target
//       {
// 	i++;
//       }
//       else // Case 3: If sum == target
//       {
// 	return std::vector<int> {i,j};
//       }
      
//     }
    
//   };

// private:
//   int binarysearch(std::vector<int> nums, int key, int start)
//   {
//     // Indices starting from left and right of array
//     int Lind = start;
//     int Rind = nums.size() - 1;

//     while (Lind < Rind)
//     {
//       // middle index
//       int Mind = (Lind + Rind)/2;

//       // If this is true, the value is in the right side of array
//       // so increment left index
//       if (nums[Mind] < key)
//       {
// 	Lind = Mind + 1;
//       }
//       // Otherwise, the value is in the left side of the array
//       // so decrement right index
//       else{
// 	Rind = Mind; // This includes case of nums[M] == key
//       }
      
//     } // End while

//     // If left and right indices match up, and the value actually
//     // matches key, then return L.  Otherwise return -1
//     return ( (Lind == Rind) && (nums[Lind] == key) ) ? Lind : -1;
//   }
  

// *******************************************************
int main()
{
  // std::vector<int> tnum = {1, 3, 4, 6, 8};
  // int target = 10;
  TwoSum tsol;
  tsol.add(1);
  std::cout << "Count of 1: " << tsol.get(1) << "\n";
  tsol.add(1);
  std::cout << "Count of 1: " << tsol.get(1) << "\n";
  tsol.add(6);
  std::cout << "Count of 6: " << tsol.get(6) << "\n";
  tsol.add(2);
  std::cout << "Count of 2: " << tsol.get(2) << "\n";
  tsol.add(3);
  std::cout << "Count of 3: " << tsol.get(3) << "\n";

  std::cout << "\n\n*********************\n\n";

  if (tsol.find(10))
  {
    std::cout << "Found a pair!\n";
  }
  else
  {
    std::cout << "Didn't find a pair!\n";
  }

  
  // std::vector<int> solution = tsol.TwoSum2(tnum, target);

  // std::cout << "Indices of the two integers are \n";
  
  // for (std::vector<int>::const_iterator i = solution.begin(); i != solution.end(); ++i)
  // {
  //   std::cout << *i << "\n";
  // }
}

  
