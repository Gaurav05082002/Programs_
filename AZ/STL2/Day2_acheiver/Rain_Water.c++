/*Rain Water

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given an array A, where each ith index represents an elevation on that index. The width of each bar is 1. You have to compute how much water it is able to trap after raining.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array. 
The second line of each test case contains N space-separated integers, where Ai denotes the height of the ith bar.


Output Format

For each test case, you have to print how much water it is able to trap after raining.


Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 105
0 ≤ Ai ≤ 105


Sample Input 1

3
3
3 0 2
5
2 0 0 4 3
5
1 2 3 1 5

Sample Output 1

2
4
2

Note

For the first test case:


For the second test case:


For the third test case:

+*/


#include <bits/stdc++.h>
using namespace std;
int work(){
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    stack<int>s;
    vector<int> lb;
    stack<int> h;
    vector<int> rb;
    for (int i = 0; i < n; i++)
    {    while(!s.empty() && v[s.top()] <= v[i]){
              s.pop();
         }
         if(s.empty()){
            lb.push_back(-1);
         }
         else{
            lb.push_back(s.top());
         }
        s.push(i);
    }
    for (int i = n-1; i >= 0; i--)
    {
        while(!h.empty()  && v[h.top()] <= v[i]){
            h.pop();
        }
        if(h.empty()){
            rb.push_back(-1);
        }
        else{
            rb.push_back(h.top());
        }
        h.push(i);
    }
    reverse(rb.begin() , rb.end());
    // for (int i = 0; i < n ; i++)
    // {
    //     cout<<lb[i]<<" ";
    
    // }
    // cout<<endl;
    //  for (int i = 0; i < n ; i++)
    // {
    //     cout<<rb[i]<<" ";
    
    // }
    int area =0;

    for (int i = 0; i < n; i++)
    {
        if(lb[i] < 0 || rb[i]< 0){
            continue;
        }
        // int height = rb[i]-lb[i]-1;
        area = area + (min(v[rb[i]] , v[lb[i]]) - v[i]);
    }
    cout<<area<<endl;
    
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