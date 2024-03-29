/*
Buy Maximum Objects I

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are N objects, and each object has some price. The price of ith object is Ai.
You have total money M, and you want to buy as many objects as possible.
Find the maximum objects that you can buy?


Input Format

The first line contains T, the number of test cases.
The first line of each test case contains N, the number of objects, and M, the money you have.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.


Output Format

For each test case, print a single number representing the maximum objects that you can buy.


Constraints

1 ≤ T ≤ 105
1 ≤ N ≤ 105
1 ≤ Ai ≤ 108
1 ≤ M ≤ 108
Sum of N over all test cases ≤ 5 * 105.


Sample Input 1

3

5 5

1 3 2 4 5

5 10

1 3 2 4 5

5 20

1 3 2 4 5


Sample Output 1

2

4

5


Note

Explanation 1:
Buy Objects with prices 1, 2.

Explanation 2:
Buy Objects with prices 1, 2, 3, 4.

Explanation 3:
Buy all objects.*/

#include <bits/stdc++.h>
using namespace std;
int work(){
     int n,k;
     cin>>n>>k;
     vector<int>v(n);
     for (int i = 0; i < n; i++)
     {
        cin>>v[i];
     }
     sort(v.begin() , v.end());
     int cnt =0;
     int i =0;
     while(k>0){
        k = k- v[i];
        i++;
        if(k>0){
            cnt++;
        }
     }
     cout<<cnt<<endl;
     

}
int main() {
    int t;
    cin>>t;
    while(t--){
        
        work();
    }
    return 0;
}