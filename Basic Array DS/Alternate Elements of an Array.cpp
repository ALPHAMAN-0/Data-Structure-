/*
Problem: Alternate Elements of an Array
=========================================

Task: Print every alternate element of an array starting from the first element.

Examples:
---------
Input:  [10, 20, 30, 40, 50]
Output: 10 30 50

Input:  [-5, 1, 4, 2, 12]
Output: -5 4 12

Approach:
---------
Iterate through the array and print elements at even indices (0, 2, 4...)
This way we print the first element, skip the second, print the third, and so on.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

vector<int> alternateElements(vector<int>& arr){
    vector<int> res;
    for(int i = 0; i < arr.size(); i += 2){
        res.push_back(arr[i]);
    }
    return res;
}
vector<int>alternateElementsRec(vector<int>& arr, int index){
    if(index >= arr.size()){
        return {};
    }
    vector<int> res = alternateElementsRec(arr, index + 2);
    res.push_back(arr[index]);
    return res;
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    vector<int> res = alternateElements(arr);  // if i use recutsion then i will use alternateElementsRec(arr, 0);
    for(int i : res){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
