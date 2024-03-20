/*Largest Rectangle

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have to find the largest rectangular area possible in a given histogram where the largest rectangle can be made of contiguous bars. Assume that all bars have the same width and the width is 1 unit.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array. 
The second line of each test case contains N space-separated integers, where Hi denotes the height of the ith bar.


Output Format

For each test case, print the largest area of the rectangle in the histogram.


Constraints

1≤ T ≤ 100
1≤ N ≤ 105
1≤ Hi ≤ 105


Sample Input 1

3
3
2 1 2
4
1 2 3 4
4
5 4 1 2

Sample Output 1

3
6
8

Note

For the first test case, take all the histograms to get area as 3*1 = 3


For the second test case, take the last two histograms to get area as 2*3 = 6


For the third test case, take the first two histograms to get area as 2*4 = 8*/
#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int findMaxRectangleArea(const vector<int>& heights) {
    int n = heights.size();

    // Compute left smaller index (ls)
    vector<int> ls;
    stack<int> ps;
    for (int i = 0; i < n; i++) {
        while (!ps.empty() && heights[ps.top()] >= heights[i]) {
            ps.pop();
        }
        if (ps.empty()) {
            ls.push_back(-1);
        } else {
            ls.push_back(ps.top());
        }
        ps.push(i);
    }

    // Compute right smaller index (rs)
    stack<int> ns;
    vector<int> rs;
    for (int i = n - 1; i >= 0; i--) {
        while (!ns.empty() && heights[ns.top()] >= heights[i]) {
            ns.pop();
        }
        if (ns.empty()) {
            rs.push_back(n);
        } else {
            rs.push_back(ns.top());
        }
        ns.push(i);
    }
    reverse(rs.begin(), rs.end());

    // Compute maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = rs[i] - ls[i] - 1;
        int area = width * heights[i];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        cout << "Maximum area of rectangle in histogram: " << findMaxRectangleArea(heights) << endl;
    }
    return 0;
}
