/*Diversify the Array

Time-Limit: 2 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A. The diversity of the array A is defined as the number of pairs i, j, i < j such that Ai ≠ Aj.
You want to maximize the diversity of the array. For that, you are allowed to make at most K operations on it, in any of which, you can select a particular element and change its value to any integer in the range 1 to 109, both inclusive.
Find out the maximum diversity of the array that you can obtain.


Input Format

The first line will contain T, number of test cases. Then the test cases follow.
The first line of each test case contains two integers N, K. where N denotes the length of array A.
The next line of each test case contains N space-separated integers, the i-th of which denotes Ai.


Output Format

For each test case, output in a single line, the answer corresponding to the test case, which should be an integer denoting the maximum possible diversity.


Constraints

1 ≤ T ≤ 20
0 ≤ K ≤ 109
2 ≤ N ≤ 105
1 ≤ Ai ≤ 109


Sample Input 1

3
3 10
1 2 3
4 2
1 1 2 2
6 2
2 3 3 2 4 4


Sample Output 1

3
6
14


Note

Explanation 1:
Every element in the array is different. The diversity is 6, which is the maximum possible.

Explanation 2:
Change the array to A = [1, 3, 2, 5]. Here we only need to change elements at 2nd and 4th positions. Now all elements are different.
The maximum diversity is 6.

Explanation 3:
Change the array to A = [5, 6, 2, 3, 4, 4]. Here we change the elements at positions 1 and 2. The maximum diversity is 14.*/

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
    map<int,int> m;
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]]++;
    }
    int x = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        int ke = it->first;
        int val = it->second;
        while(k>0){
            if(val > 1){
                m[ke]--;
                val--;
                x++;
                k--;
            }
            else{
                break;
            }
        }

    }
    int y = n;
    int z = (y*(y-1))/2;
    int s =0;
    for (auto it = m.begin(); it != m.end(); it++){
           int ke = it->first;
        int val = it->second;
        if(val > 1){
            s = s+((val*(val-1))/2);
        }
    }
    cout<<"z="<<z<<"and"<<" "<<"S="<<s<<endl;
    cout<<(z-s)<<endl;
    
    
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