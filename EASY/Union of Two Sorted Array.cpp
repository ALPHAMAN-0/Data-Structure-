/*
Problem:
Given two sorted arrays a[] and b[], 
the task is to return union of both 
arrays in sorted order. Union contains 
all distinct elements present in 
either array. The input arrays may 
contain duplicates.

Approach:
The idea is to find the union using 
merge step in merge sort. We maintain 
two pointers to traverse both arrays 
simultaneously. 

If element in first array is smaller, 
add it to result and move first 
array pointer forward.

If element in second array is smaller, 
add it to result and move second 
array pointer forward. 

If elements are equal, add one of them 
and move both pointers forward.

While traversing, compare current 
element with previous element and 
skip current element if same as 
previous. This ensures union contains 
only distinct elements.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findUnion(vector<int>& a, vector<int>& b) {
    vector<int> res; 
    int n = a.size();
    int m = b.size();
  
    // This is similar to merge of merge sort
    int i = 0, j = 0;    
    while(i < n && j < m) {
      
        // Skip duplicate elements in the first array
        if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      
      	// Skip duplicate elements in the second array
      	if(j > 0 && b[j - 1] == b[j]) {
          	j++;
          	continue;
        }
      	
      	// select and add the smaller element and move
        if(a[i] < b[j]) {
          	res.push_back(a[i]);
            i++;
        }
        else if(a[i] > b[j]) {
          	res.push_back(b[j]);
            j++;
        }
      
        // If equal, then add to result and move both 
        else {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
  	
  	// Add the remaining elements of a[]
  	while (i < n) {
      	
      	// Skip duplicate elements in the first array
      	if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      	res.push_back(a[i]);
      	i++;
    }
  
  	// Add the remaining elements of b[]
  	while (j < m) {
      
      	// Skip duplicate elements in the second array
      	if(j > 0 && b[j - 1] == b[j]) {
            j++;
            continue;
        }
      	res.push_back(b[j]);
      	j++;
    }
    return res; 
}

int main() {
  
    vector<int> a = {1, 1, 2, 2, 2, 4};
    vector<int> b = {2, 2, 4, 4};
  
    vector<int> res = findUnion(a, b);
    for (int x : res) {
        cout << x << " ";
    }
}
