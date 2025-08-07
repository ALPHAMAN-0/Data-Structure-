#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class MissingElements {
public:
    int findMissingElementsRange(const vector<int>& arr, int start, int end)
    {
        int maxValue = *max_element(arr.begin(), arr.end());
        int minValue = *min_element(arr.begin(), arr.end());

        unordered_set<int> elementsSet(arr.begin(),arr.end());
        
        return (maxValue - minValue +1) -elementsSet.size();

    }
};
