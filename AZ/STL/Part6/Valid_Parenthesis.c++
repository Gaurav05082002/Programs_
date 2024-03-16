/*Valid Parentheses AZ101

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You are given a string S. Find the minimum number of parentheses you should add to make the parentheses valid.

A parentheses is valid if:

It is an empty string
It can be written as AB where A and B are valid parentheses
It can be written as (A) where is a valid parentheses

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one string S.


Output Format

For each test case, print the minimum number of parentheses you should add to make the parentheses valid.


Constraints

1 ≤ T ≤ 2 x 105
1 ≤ |S| ≤ 105
It is guaranteed that the sum of |S| over all test cases does not exceed 106. 


Sample Input 1

3
(())))
()()(()
))((

Sample Output 1

2
1
4

Note

For the first test case, we need to add 2 opening brackets: (((())))

For the second test case, we need to add 1 closing bracket: ()()(())

For the third test case, we need two add 2 opening and 2 closing brackets: (())(())*/

#include <bits/stdc++.h>
using namespace std;
int work(){
    string s;
    cin>>s;
    int open =0;
    int close =0;
    int ans =0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' ){
        
            open++;
        }
        if(s[i] == ')' ){
             if(open > 0){
                open--;
             }
             else{
                close++;
             }
        }
        
    }
    ans = open+close;
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