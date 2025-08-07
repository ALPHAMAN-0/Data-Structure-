/*
Problem:
Given n points on a 2D plane as pairs of (x, y) coordinates, find the maximum number of points that lie on the same straight line.

Example:
Input: points[] = {-1, 1}, {0, 0}, {1, 1}, {2, 2}, {3, 3}, {3, 4}
Output: 4
Explanation: The points {0, 0}, {1, 1}, {2, 2}, {3, 3} all lie on the same line.

Approach:
- For each point p, calculate the slope with every other point.
- Use a map to count how many points share the same slope with p (i.e., are collinear).
- The slope between (x1, y1) and (x2, y2) is (y2 - y1) / (x2 - x1).
- To avoid precision issues with floating-point division, store the slope as a reduced pair (y2 - y1, x2 - x1) using their greatest common divisor (gcd).
- Handle vertical lines and overlapping points separately.
- For each point, update the maximum count found so far.

Complexity:
- Time: O(n^2)
- Space: O(n)
*/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <boost/functional/hash.hpp>
using namespace std;

class solve
{
public:
    int maxPointOnSameLine(vector<pair<int, int>> points)
    {
        int N = points.size();
        if (N < 2)
            return N;

        int maxPoint = 0;
        int curMax, overlapPoints, verticalPoints;
        unordered_map<pair<int, int>, int, boost::hash<pair<int, int>>> slopeMap;

        for (int i = 0; i < N; i++)
        {
            curMax = overlapPoints = verticalPoints = 0;
            for (int j = i + 1; j < N; j++)
            {
                if (points[i] == points[j])
                    overlapPoints++;
                else if (points[i].first == points[j].first)
                    verticalPoints++;
                else
                {
                    int yDif = points[j].second - points[i].second;
                    int xDif = points[j].first - points[i].first;
                    int g = __gcd(xDif, yDif);
                    yDif /= g;
                    xDif /= g;
                    slopeMap[make_pair(yDif, xDif)]++;
                    curMax = max(curMax, slopeMap[make_pair(yDif, xDif)]);
                }
                curMax = max(curMax, verticalPoints);
            }
            maxPoint = max(maxPoint, curMax + overlapPoints + 1);
            slopeMap.clear();
        }
        return maxPoint;
    }
};

int main()
{
    const int N = 6;
    int arr[N][2] = {{-1, 1}, {0, 0}, {1, 1}, {2, 2}, {3, 3}, {3, 4}};
    vector<pair<int, int>> points;
    for (int i = 0; i < N; i++)
        points.push_back(make_pair(arr[i][0], arr[i][1]));
    solve obj;
    cout << obj.maxPointOnSameLine(points) << endl;
    return 0;
}
