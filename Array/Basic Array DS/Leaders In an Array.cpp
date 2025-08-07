/*
LEADERS IN AN ARRAY
-------------------
Problem:
    Find all leaders in an array of positive integers.
    A leader is an element greater than or equal to
    all elements to its right.
    Note: The rightmost element is always a leader.

Solution Approaches:
    1) Scan right-to-left, tracking maximum so far.
         If current > max_so_far, it's a leader.
         
    2) Alternative: Use nested loops (less efficient).
         Outer loop: left to right
         Inner loop: check if current > all elements to right
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leaders(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size()-1;
    int maxRight = arr[n];
    res.push_back(maxRight);

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= maxRight)
        {
            maxRight = arr[i];
            res.push_back(maxRight);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> res = leaders(arr);
    for (int x : res)
    {
        cout << x << " ";
    }
    return 0;
}
