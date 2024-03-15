// Set Queries AZ101

// Time-Limit: 1 sec Score: 0/100
// Difficulty : 
//  Memory: 256 MB Accepted Submissions: 100
// Description

// You have an empty set and can perform the following operations on it:

// 1 x - Add integer x to the set
// 2 x - Find the smallest integer that is not present in the set, which is greater than or equal to x.

// Input Format

// The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

// The first line of each test case contains one integer Q - the number of queries. 

// Each of the next Q lines contain two space-separated integers ti and xi - type and value of the query.


// Output Format

// For each test case, print the answer for the queries.


// Constraints

// 1≤ T ≤ 105

// 1≤ Q ≤ 105

// 1≤ ti ≤ 2

// 1≤ xi ≤ 1012

// It is guaranteed that the sum of Q over all test cases does not exceed 106.


// Sample Input 1

// 2
// 4
// 1 1
// 1 3
// 2 1
// 2 4
// 3
// 2 4
// 1 4
// 2 4

// Sample Output 1

// 2
// 4
// 4
// 5
#include <bits/stdc++.h>
using namespace std;

set<int> s;

void work(int n) {
    if (n == 1) {
        int k;
        cin >> k;
        s.insert(k);
    }
    if (n == 2) {
        int k;
        cin >> k;
        auto a = s.lower_bound(k);
        auto b = s.upper_bound(k);
        int z = k + 1;
        if (a != b) {
            cout << z << endl;
            return;
        } else {
            for (auto it = b; it != s.end(); it++) {
                if (z != *it) {
                    cout << z << endl;
                    return;
                } else {
                    z++;
                }
            }
            cout << z << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        work(n);
    }
    return 0;
}
