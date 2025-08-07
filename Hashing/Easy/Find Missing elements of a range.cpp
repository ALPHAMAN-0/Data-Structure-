#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class MissingElements {
public:
    vector<int> findMissingElements(const vector<int>& arr, int start, int end)
    {
        unordered_set<int> elementsSet(arr.begin(),arr.end());
        vector<int> missingElements;
        for (int i = start; i <= end; ++i)
        {
            if (elementsSet.find(i) == elementsSet.end())
            {
                missingElements.push_back(i);   
            }
        }
        return missingElements;

    }
};
