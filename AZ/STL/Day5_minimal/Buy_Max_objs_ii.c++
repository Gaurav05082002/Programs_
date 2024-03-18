/*Buy Maximum Objects II

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are N objects, and each object has some price. The price of ith object is Ai.
You have been asked Q queries. In each query, you have been given total money M, and find the maximum number of objects that you can buy.


Input Format

The first line of each test case contains N, the number of objects, and Q, total queries.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.
Next, Q lines contain a number M, the total money.


Output Format

For each query, print a single number in a new line representing the maximum objects that you can buy.


Constraints

1 ≤ N, Q ≤ 105
1 ≤ Ai ≤ 108
1 ≤ M ≤ 108


Sample Input 1

5 4
1 4 2 9 6
1
5
10
25

Sample Output 1

1
2
3
5

Note

M = 1, buy Object with price 1.
M = 5, buy Objects with prices 1, 4.
M = 10, buy Objects with prices 1, 2, 4.
M = 25, buy Objects with prices 1, 2, 4, 9, 6.*/


#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    vector<int> sim;
    for (int i = 0; i < n; i++)
    {  
        cin>>v[i];
        
    }
    sort(v.begin() ,v.end());
    int sum=0;
    // 1 2 4 6 9
    // 1 3 7 13 22
    for (int  i = 0; i < n; i++)
    {
       if(i==0){
        sim.push_back(v[i]);
        sum = sum + v[i];
        continue;
       }
       sum = sum + v[i];
       sim.push_back(sum);
    
    }
    
    
    while(t--){
        int m;
        cin>>m;
        auto it = upper_bound(sim.begin() , sim.end() , m);
        if(it == sim.end()){
            cout<<n<<endl;
        }
        else{
            cout<<(it-sim.begin())<<endl;
        }
     
    }
    return 0;
}
