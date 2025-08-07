/*
Problem:
Given two arrays a[] and b[], the task is to return 
union of both the arrays in any order.

Note: 
Union of two arrays is an array having all distinct 
elements that are present in either array.

Approach:
The idea is to use a Hash Set, which helps in keeping 
only unique elements by removing duplicates. We first 
create an empty Hash Set and add elements from both arrays. 
The Hash Set ensures that no duplicates are stored. 
After adding all the elements, we can create the final 
union array by iterating through the Hash Set.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b) {
  	unordered_set<int> st;  
  
    // Put all elements of a[] in st
    for (int i = 0; i < a.size(); i++) 
      	st.insert(a[i]);
  	
  	// Put all elements of b[] in st
    for (int i = 0; i < b.size(); i++) 
      	st.insert(b[i]);
  	
    vector<int> res;                            
  	
  	// iterate through the set to fill the result array 
  	for(auto it: st) 
      	res.push_back(it);
    
    return res;
}

