/*
Count the Pairs

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array A of size N. You need to find the number of pairs (i, j) , i != j, such that A[i]+A[j] ≤ X.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N  X.

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the number of pairs (i, j) , i != j, such that A[i]+A[j] ≤ X.


Constraints

1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 106

1≤ X ≤ 106

It is guaranteed that the sum of N over all test cases does not exceed 105.


Sample Input 1

2

5 4

1 2 2 3 4

3 10

5 5 5


Sample Output 1

8

6


Note

For the first test case, the following pairs have sum ≤ 4: (1,2), (1,2), (1,3), (2,1), (2,2), (2,1), (2,2), (3,1)

For the second test case, the following pairs have sum ≤ 10: (5,5), (5,5), (5,5), (5,5), (5,5), (5,5)*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        long long pairs = 0;

        for (int i = 0; i < n; ++i) {
            int j = upper_bound(A.begin(), A.end(), x - A[i]) - A.begin() - 1;
            pairs += max(0, j - i);
        }

        cout << pairs << endl;
    }

    return 0;
}
