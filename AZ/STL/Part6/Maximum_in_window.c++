/*Maximum in Window

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A of size N and a positive integer K (≤ N). A1, A2, ..., AN are the elements of the array.
Let Bi = max (Ai, Ai+1, ..., Ai+K-1), for 1 ≤ i ≤ N - K + 1. 
Find Bi values for all is such that 1 ≤ i ≤ N - K + 1.


Input Format

The first line contains T, the number of test cases. 
The first line of each test case contains N, the number of integers in an array A and K.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.


Output Format

For each test case, print array B as B1 B2 ... BN-K+1 in a new line.


Constraints

1 ≤ T ≤ 100000
1 ≤ K ≤ N ≤ 100000
-109 ≤ Ai ≤ 109
Sum of N over all test cases ≤ 5 * 105.


Sample Input 1

4

9 3

1 2 3 1 4 5 2 3 6

5 5

1 -4 3 -3 -9

4 1

-3 1 -8 3

5 2

-1 -1 -1 -1 -1


Sample Output 1

3 3 4 5 5 5 6

3

-3 1 -8 3

-1 -1 -1 -1


Note

Explanation 1:
B1 = max(1, 2, 3) = 3
B2 = max(2, 3, 1) = 3
B3 = max(3, 1, 4) = 4
B4 = max(1, 4, 5) = 5
B5 = max(4, 5, 2) = 5
B6 = max(5, 2, 3) = 5
B7 = max(2, 3, 6) = 6

Explanation 2:
B1 = max(1, -4, 3, -3, -9) = 3*/

#include <bits/stdc++.h>
using namespace std;
int work(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    set<int> s;
    for (int i = 0; i < k; i++)
    {
        s.insert(v[i]);

    }
    ans.push_back(*(--s.end()));
    for (int i = 1; i < n; i++)
    {    if(i+k-1 > n-1){
          break;
         }
        if(i>0){
              s.erase(s.find(v[i-1]));
         }
        s.insert(v[i+k-1]);

        ans.push_back(*(--s.end()));
      
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
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