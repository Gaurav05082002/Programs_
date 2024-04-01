/*Running Mean, Median and Mode AZ101

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You have an empty array and can perform the following operations on it:

insert x - add integer x to the array
remove x - remove integer x from the array. It's guaranteed the element present in it.
getMean - find the mean of elements currently presents in the array.
getMedian - find the median of elements currently present in the array,  if the count of the numbers is even, take the average of the two middle elements.
getMode - find the mode of elements currently present in the array, if there is more than one potential element, assume that the mode is the smaller of all.
If the array is empty at the point a query is asked about a metric(mean, median, mode), print -1.

If any of the answers for the query is a fraction, let's say, P / Q in reduced form, the return the number (P*Q-1) Modulo 1000000007.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer Q - the number of queries. 
Each of the next Q lines contains a string S and integer X or just a string S - description of the query.


Output Format

For each test case, print the answer for the queries.


Constraints

1 ≤ T ≤ 105
1 ≤ Q ≤ 105
1 ≤ x ≤ 109
It is guaranteed that the sum of Q over all test cases does not exceed 105.


Sample Input 1

1
12
insert 4
insert 3
insert 5
getMean
getMedian
getMode
insert 4
remove 3
insert 5
getMean
getMedian
getMode

Sample Output 1

4
4
3
500000008
500000008
4

Note

Array becomes: [4]
Array becomes [3, 4]
Array becomes [3, 4, 5]
Mean = (3+4+5) / 3 = 4
Median = 4 (middle element)
Mode = 3 (since it is smallest in value)
Array becomes [3, 4, 4, 5]
Array becomes [4, 4, 5]
Array becomes [4, 4, 5, 5]
Mean = (4+4+5+5)/4 = 4.5 (=500000008 in mod domain)
Median = (4+5)/2 = 4.5 (average of the two middle elements)
Mode = 4 (since it is smallest in value)*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

const long long MOD = 1000000007;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long getModuloInverse(long long a, long long m) {
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

long long getMean(const vector<int>& nums) {
    long long sum = 0;
    for (int num : nums) {
        sum += num;
    }
    long long mean = sum / nums.size();
    return mean % MOD;
}

long long getMedian(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n % 2 == 0) {
        long long median = (nums[n / 2] + nums[(n / 2) - 1]) % MOD;
        return median;
    } else {
        long long median = nums[n / 2] % MOD;
        return median;
    }
}

long long getMode(const vector<int>& nums) {
    map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    int mode = INT_MAX;
    int maxFreq = INT_MIN;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        if (it->second > maxFreq || (it->second == maxFreq && it->first < mode)) {
            maxFreq = it->second;
            mode = it->first;
        }
    }
    return mode % MOD;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;
        vector<int> nums;
        
        while (q--) {
            string query;
            cin >> query;
            
            if (query == "insert") {
                int x;
                cin >> x;
                nums.push_back(x);
            } else if (query == "remove") {
                int x;
                cin >> x;
                auto it = find(nums.begin(), nums.end(), x);
                if (it != nums.end()) {
                    nums.erase(it);
                }
            } else if (query == "getMean") {
                if (nums.empty()) {
                    cout << "-1" << endl;
                } else {
                    long long mean = getMean(nums);
                    cout << mean << endl;
                }
            } else if (query == "getMedian") {
                if (nums.empty()) {
                    cout << "-1" << endl;
                } else {
                    long long median = getMedian(nums);
                    cout << median << endl;
                }
            } else if (query == "getMode") {
                if (nums.empty()) {
                    cout << "-1" << endl;
                } else {
                    long long mode = getMode(nums);
                    cout << mode << endl;
                }
            }
        }
    }

    return 0;
}
