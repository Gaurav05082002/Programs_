// Nearest Smaller Values AZ101

// Time-Limit: 1 sec Score: 0/100
// Difficulty : 
//  Memory: 256 MB Accepted Submissions: 100
// Description

// You are given an array of N integers. For each position, find the nearest position to its left having a smaller value. (1-based indexing)


// Input Format

// The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

// The first line of each test case contains one integer N - the length of the array. 

// The second line of each test case contains N space-separated integers.


// Output Format

// For each test case, print N space-separated integers, for each position, the nearest position to its left having a smaller value.  If no position to its left has a smaller value, print 0.


// Constraints

// 1≤ T ≤ 105

// 1≤ N ≤ 105

// 1≤ Ai ≤ 109

// It is guaranteed that the sum of N over all test cases does not exceed 106.


// Sample Input 1

// 3
// 5
// 3 5 1 6 2
// 4
// 1 1 2 1
// 5
// 1 3 2 6 6

// Sample Output 1

// 0 1 0 3 3 
// 0 0 2 0 
// 0 1 1 3 3


#include <bits/stdc++.h>
using namespace std;
int work() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if (s.empty()) {
            b[i] = -1;
        } else {
            b[i] = s.top();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] + 1 << " ";
    }

    return 0;
}
int main() {
    int t;
    cin>>t;
    while(t--){
       
        work();
        cout<<endl;
    }
    return 0;
}