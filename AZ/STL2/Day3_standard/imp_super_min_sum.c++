/*Super Minimum Sum

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A of size N. A1, A2, ..., AN are the elements of the array. All elements in the array A are distinct.
Find the sum of the minimum of all subarrays possible of array A.

A subarray of an -element array is an array composed from a contiguous block of the original array's elements


Input Format

The first line contains T, the number of test cases.
The first line of each test case contains N, the number of integers in an array A.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.


Output Format

For each test case, print a single number representing the sum of the minimum of all subarrays of A.


Constraints

1 ≤ T ≤ 100000
1 ≤ N ≤ 100000
1 ≤ Ai ≤ 106
Sum of N over all test cases ≤ 5 * 105.
It is guaranteed that all elements in an array A are distinct.


Sample Input 1

5
3
1 2 3
2
1 5
4
2 3 4 10
8
1000000 1000001 1000002 1000003 1000004 1000005 1000006 1000007
3
3 1 2

Sample Output 1

10
7
35
36000084
9

Note

Explanation 1:
Min{1} + Min{1, 2} + Min{1, 2, 3} + Min{2} + Min{2, 3} + Min{3} = 1 + 1 + 1 + 2 + 2 + 3 = 10

Explanation 2:
Min{1} + Min{1, 5} + Min{5} = 1 + 1 + 5 = 7*/

// must check gfg
// important part 
/*
// calculating required resultult
    for (int i = 0; i < n; ++i)
        result = (result + A[i] * left[i] * right[i]);
 
    return result;*/

#include <bits/stdc++.h>
using namespace std;

int work() {
    int n;
    cin >> n;
    vector<int> A(n);
    int left[n], right[n];
 
    stack<pair<int, int> > s1, s2;
 
    // getting number of element strictly larger 
    // than A[i] on Left.
    for (int i = 0; i < n; ++i) {
        int cnt = 1;
 
        // get elements from stack until element 
        // greater than A[i] found
        while (!s1.empty() && (s1.top().first) > A[i]) {
            cnt += s1.top().second;
            s1.pop();
        }
 
        s1.push({ A[i], cnt });
        left[i] = cnt;
    }
 
    // getting number of element larger than A[i] on Right.
    for (int i = n - 1; i >= 0; --i) {
        int cnt = 1;
 
        // get elements from stack until element greater
        // or equal to A[i] found
        while (!s2.empty() && (s2.top().first) >= A[i]) {
            cnt += s2.top().second;
            s2.pop();
        }
 
        s2.push({ A[i], cnt });
        right[i] = cnt;
    }
 
    int result = 0;
 
    // calculating required resultult
    for (int i = 0; i < n; ++i)
        result = (result + A[i] * left[i] * right[i]);
 

    cout << result <<endl;

    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        work();
    }
    return 0;
}
