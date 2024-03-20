/*Support Queries II

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Design a Data Structure which can support the following queries:

Initially, the structure is empty. You have given an integer K. 

The structure is arranged in the order from greater elements to smaller elements. So when we say top K elements, we mean the top K largest elements.

1 x: Add x in structure.

2 x: Remove x from the structure if present in the structure. If x doesn't present in the structure, do nothing. If there are multiple occurrences of x, delete only one occurrence of x.

3 ?: Print the sum of the top K elements. If the structure contains less than K elements, then print the sum of all elements present in the structure. If the structure is empty, then print 0.


Input Format

The first line of input contains Q and K - the number of queries.
Next, Q lines contain queries of the format specified in the statement. 


Output Format

For queries of type 3, print the answer in a new line.


Constraints

1 ≤ Q, K ≤ 105
0 ≤ x ≤ 109


Sample Input 1

17 3
1 5
1 2
1 3
1 6
3 ?
2 3
3 ?
2 2
3 ?
2 2
3 ?
2 5
3 ?
2 5
3 ?
2 6
3 ?

Sample Output 1

14
13
11
11
6
6
0*/
#include <iostream>
#include <map>
using namespace std;

int main() {
    int q, k;
    cin >> q >> k;
    multimap<int, int, greater<int>> m;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int val;
            cin >> val;
            m.insert({val, 1});
        } else if (x == 2) {
            int val;
            cin >> val;
            auto it = m.find(val);
            if (it != m.end() && it->second > 0) {
                it->second--;
            }
        } else {
            int sum = 0;
            if (m.size() < k) {
                for (auto it = m.begin(); it != m.end(); it++) {
                    sum += it->first * it->second;
                }
                cout << sum << endl;
            } else if (m.size() >= k) {
                int l = 0;
                for (auto it = m.begin(); it != m.end(); it++) {
                    sum += it->first * it->second;
                    l++;
                    if (l == k) {
                        break;
                    }
                }
                cout << sum << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
