/*Set Operations AZ101

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given two sets, A and B of N and M integers respectively. There are no duplicate integers in each respective array. Find the set union, set intersection and set difference (A-B) of the two sets in sorted order.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, M - the length of the sets.

The second line of each test case contains N space-separated integers.

The third line of each test case contains M space-separated integers.


Output Format

For each test case, print the set union, set intersection and set difference (A-B) of the two sets  in sorted order, each on a separate line.


Constraints

1≤ T ≤ 105

1≤ N, M ≤ 10^4

1≤ Ai, Bi ≤ 109

It is guaranteed that the sum of N and the sum of M over all test cases does not exceed 2*10^5.


Sample Input 1

3
4 5
2 4 1 5
4 5 6 9 3
2 3
4 5
6 7 1
3 3
1 2 3
1 2 3

Sample Output 1

1 2 3 4 5 6 9 
4 5 
1 2 
1 4 5 6 7 

4 5 
1 2 3 
1 2 3*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void findSetOperations(const set<int>& A, const set<int>& B) {
    // Set union
    vector<int> unionSet(A.size() + B.size());
    auto it_union = set_union(A.begin(), A.end(), B.begin(), B.end(), unionSet.begin());
    unionSet.resize(it_union - unionSet.begin());

    // Set intersection
    vector<int> intersectionSet(min(A.size(), B.size()));
    auto it_intersection = set_intersection(A.begin(), A.end(), B.begin(), B.end(), intersectionSet.begin());
    intersectionSet.resize(it_intersection - intersectionSet.begin());

    // Set difference A - B
    vector<int> differenceSet(A.size());
    auto it_difference = set_difference(A.begin(), A.end(), B.begin(), B.end(), differenceSet.begin());
    differenceSet.resize(it_difference - differenceSet.begin());

    // Output results
    cout << "Union:";
    for (int num : unionSet) {
        cout << " " << num;
    }
    cout << endl;

    cout << "Intersection:";
    for (int num : intersectionSet) {
        cout << " " << num;
    }
    cout << endl;

    cout << "Difference (A - B):";
    for (int num : differenceSet) {
        cout << " " << num;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        set<int> A, B;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
            A.insert(num);
        }
        for (int i = 0; i < M; ++i) {
            int num;
            cin >> num;
            B.insert(num);
        }
        findSetOperations(A, B);
    }
    return 0;
}
