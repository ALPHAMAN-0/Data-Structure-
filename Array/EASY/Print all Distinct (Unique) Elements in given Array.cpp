/*
  Problem Statement : Given an integer array arr[], print all distinct elements from this array. The given array may contain duplicates and the output should contain every element only once.
  
  Idea     We can use Hashing to store distinct element. The idea is to insert all the elements in a hash set and then traverse the hash set to store the distinct elements in the resultant array.

  Time Complexity: O(n)
  Space Complexity: O(n)

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
     cout<<"Hello ";
    return 0;
}