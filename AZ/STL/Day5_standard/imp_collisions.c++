/*Collisions

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are N balls on the X-axis and M balls on the Y-axis. At the time, t=0, each ball on X-axis is thrown parallel to the Y-axis in the positive Y direction. Similarly, each ball on Y-axis is thrown parallel to the X-axis in the positive X direction. At any time, if two balls collide, they disappear. A collision can only happen between the ball thrown from X-axis and the ball thrown from Y-axis. No two balls from X-axis or Y-axis can collide. A ball can take part in at max one collision. You have to find the total number of collisions. 


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains two space-separated integers N and M - the number of balls on the X-axis and Y-axis respectively.
For each test case, N lines follow. The i-th of the line contains two space-separated integers Xi and Ui, the position and speed of the i-th ball respectively.
For each test case, M lines follow. The i-th of the line contains two space-separated integers Yi and Vi, the position and speed of the i-th ball respectively.


Output Format

For each test case, print the number of collisions on a separate line.


Constraints

1≤ T ≤ 100
1≤ N, M ≤ 105
1≤ Xi, Ui, Yi, Vi ≤ 109


Sample Input 1

`

Sample Output 1

1
1
2

Note

In the first test case of the example, at t=1 the balls collide. The number of collisions is 1.

In the second test case of the example, at t=1, the first ball on X-axis and the first ball on Y-axis collide and disappear. The number of collisions is 1.

In the third test case of the example, at t=⅓, the second ball on X-axis and the first ball on Y-axis collide and disappear. At t=1, the first ball on X-axis and the second ball on Y-axis collide and disappear. The number of collisions is 2.*/


#include <bits/stdc++.h>
using namespace std;
int work(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    map<int,int> mx , my;
    for (int i = 0; i < n; i++)
    {
        int x , u;
        cin>>x>>u;
        mx[x*u]++;
    }
    for (int i = 0; i < m; i++)
    {
        int y , v;
        cin>>y>>v;
        my[y*v]++;
    }
    for (auto it = mx.begin(); it != mx.end(); it++)
    {
        int key = it->first;
        int val = it->second;

        if(my[key] == 0){
            continue;

        }
        if(my[key] ==  val){
            ans=ans+val;
        }
        if(my[key] != val){
            ans = ans + min(my[key] , val);
        }
 

    }
    
    cout<<ans<<endl;
    return 0;
    
    
}
int main() {
    int t;
    cin>>t;
    while(t--){
     
        work();
    }
    return 0;
}
