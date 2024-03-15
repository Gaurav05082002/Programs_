// The Magical Candy Bag AZ101

// Time-Limit: 1 sec Score: 0/100
// Difficulty : 
//  Memory: 256 MB Accepted Submissions: 100
// Description

// You have N magical candy bag. The i-th bag contains Ai candies. In each minute you can eat all the candies, Ai of one bag, after that, the candies become [Ai / 2] where [x] is the greatest integer less than x. You have K minutes, find the maximum number of candies you can eat.


// Input Format

// The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

// The first line of each test case contains two space-separated integers N, K - the number of bags and the number of minutes.

// The second line of each test case contains N space-separated integers.


// Output Format

// For each test case, print the maximum number of candies you can eat.


// Constraints

// 1≤ T ≤ 105

// 1≤ N ≤ 105

// 0≤ K ≤ 105

// 1≤ Ai ≤ 109

// It is guaranteed that the sum of K over all test cases does not exceed 106.


// Sample Input 1

// 3
// 4 2
// 4 3 5 1
// 1 2
// 4
// 6 3
// 3 2 2 5 1 2

// Sample Output 1

// 9
// 6
// 10

// Note

// For the first test case, first take 5 candies then the bag becomes: [4, 3, 2, 1], and then take 4 candies to get a total 5+4 = 9 candies.

// For the second test case, first take 4 candies, then bag becomes: [2] and then take 2 candies to get a total 4+2 = 6 candies.

// For the third test case, first take 5 candies, then bag becomes: [3, 2, 2, 2, 1, 2] and then take 3 candies, then bag becomes: [1, 2, 2, 2, 1, 2], then take 2 candies to get a total 5+3+2 = 10 candies.

#include <bits/stdc++.h>
using namespace std;

int work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;

    for (int i = 0; i < k; i++) {
        sort(a.begin(), a.end() , greater<int>()); // Sort the array
        sum += a[0];               // Add the smallest element to the sum
        a[0] /= 2;                 // Divide the smallest element by 2
    }

    cout << sum << endl;
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







#include <iostream>
#include <vector>
#include <queue>
#include <functional> // for greater<int>

using namespace std;

long long maxCandies(int n, int k, vector<int>& bags) {
    // Priority queue (max heap) to store candies
    priority_queue<int> pq(bags.begin(), bags.end());

    long long totalCandies = 0;

    // Perform K operations
    for (int i = 0; i < k; ++i) {
        // Get the maximum candies from the bag
        int candies = pq.top();
        pq.pop();

        // Add candies to total count
        totalCandies += candies;

        // Reduce candies and push back to the priority queue
        pq.push(candies / 2);
    }

    return totalCandies;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> bags(n);
        for (int i = 0; i < n; ++i) {
            cin >> bags[i];
        }

        // Calculate and print the maximum number of candies
        cout << maxCandies(n, k, bags) << endl;
    }

    return 0;
}
