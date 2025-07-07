/*
    Problem :Given an integer array arr[], print all distinct elements from this array.
    The given array may contain duplicates and the output should contain every element only once

    Solve Way
    1) We can use Hashing to store distinct element. 
    The idea is to insert all the elements in a hash set and then traverse the hash set to store the distinct elements in the resultant array.
    
    2)The idea is to sort the array so that all occurrences of every element become consecutive. Once the occurrences become consecutive,
    we can traverse the sorted array and print distinct elements by ignoring elements if they are same as the previous element.

*/


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// function to return all distinct elements
vector<int> findDistinct(vector<int> &arr) {
      
    // Initialize set with all elements of array
    unordered_set<int> st (arr.begin(), arr.end());
  
    // Return the result array by inserting all 
    // elements from hash set
      return vector<int> (st.begin(), st.end());
}

int main () {
    vector<int> arr = {12, 10, 9, 45, 2, 10, 10, 45};
    
      vector<int> res = findDistinct(arr);
      for (int ele: res)
          cout << ele << " ";
    return 0;
}
