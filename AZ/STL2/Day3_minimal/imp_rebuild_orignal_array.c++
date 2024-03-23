/*Rebuild Original Array

Time-Limit: 4 sec Score: 0/100
Difficulty :
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

Your class teacher wrote N integers on the board. One of your classmates was being mischievous, he replaced the N integers with all possible subset sums of the array when the teacher was not in the class.
Suppose that the integers on the board were [2,1] then the subsets will be: {}, {2}, {1}, {2,1} and the subset sums will be: {0,2,1,3}.
Your task is to rebuild the original array given by your teacher.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the number of elements in the initial array.
The second line of each test case contains 2N space-separated integers, the new values on the board.


Output Format

For each test case, print N space-separated integers in non-decreasing order.
It is guaranteed that a solution always exists.


Constraints

1 ≤ T ≤ 50
1 ≤ N ≤ 15
0 ≤ Ai ≤ 1015


Sample Input 1

3
2
0 1 2 3
3
0 1 3 4 5 6 8 9
3
0 1 1 1 2 2 2 3

Sample Output 1

1 2
1 3 5
1 1 1

Note

In the first test case of the example, the original array is [1,2] which has the following subset - {}, {1}, {2}, {1,2}. Their respective sums are 0,1,2,3.

In the third test case of the example, the original array is [1,1,1] which has the following subset - {}, {1}, {1}, {1}, {1,1}, {1,1}, {1,1}, {1,1,1}. Their respective sums are 0,1,1,1,2,2,2,3*/

#include <bits/stdc++.h>
using namespace std;

int work() {
    int a;
    cin >> a;
    int n = 1 << a;
    vector<int>v(n+1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    multimap<int, int> m;
    vector<int>ans;
    ans.push_back(v[1]);
    m.insert({v[1], 0});
    ans.push_back(v[2]);
    m.insert({v[2], 0});
    int z = v[1] + v[2];
    m.insert({z, 1});

    for (int i = 3; i < n; i++) {
        int eject = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->first == v[i] && it->second == 1) {
                m.erase(it);
                m.insert({v[i], 0});
                cout<<"reach1"<<endl;
                eject = 1;
                break;
            }
        }
        if (!eject) {
            ans.push_back(v[i]);
            int p=0;
            for (auto it = m.begin(); it != m.end(); it++) {
            
                   p++;
                
            }
            for (auto it = m.begin(); it != m.end() && p>0; it++) {
            
                    int l = it->first + v[i];
                    m.insert({l, 1});
                    p--;
                
            }
        }
        if(ans.size()==a){
             cout<<"reach3"<<endl;
            break;
        }
    }
    

    for (int i = 0; i < ans.size(); i++) {
        
        cout << ans[i] << " ";
    }
    cout << endl;
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
