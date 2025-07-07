/*
    Problem ;Given two sorted arrays a[] and b[], the task is to return intersection. 
    Intersection of two arrays is said to be elements that are common in both arrays. 
    The intersection should not count duplicate elements and the result should contain items in sorted order.

    Solve Way
    1. We simultaneously traverse both a[] and b[] from the left side. While traversing, we avoid duplicates in a[].
    We do not need to do it for b[] because once we have a match, we move ahead in a[] and b[] both.
    2. If current elements are not same, we skip the smaller of the two. If current element of a[] is smaller, 
    we move ahead in a[] and if current of b[] is smaller, we move ahead in b[].
    3. Else (If same), we add one occurrence of the current element to the result and move ahead in both a[] and b[].
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

vector<int> intersection(vector<int>& a,  vector<int>& b) {
    vector<int> res; 
    int m = a.size();
    int n = b.size();
  
    // This is similar to merge of merge sort
    int i = 0, j = 0;    
    while(i < m && j < n) {
      
        // Skip duplicate elements in the first array
        if(i > 0 && a[i - 1] == a[i]) {
            i++;
            continue;
        }
      
        // Skip the smaller
        if(a[i] < b[j]) {
            i++;
        }
        else if(a[i] > b[j]) {
            j++;
        }
      
        // If equal, add to result and move both 
        else {
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
    return res; 
}

int main() {
    vector<int> a = {3, 5, 10, 10, 10, 15, 15, 20};
    vector<int> b = {5, 10, 10, 15, 30};
    vector<int> res = intersection(a, b);
    for (int x : res) {
        cout << x << " ";
    }
}
