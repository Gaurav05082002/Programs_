/*Reduce the Array AZ101

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Description

You are given an array of N integers. In one operation, remove any two elements in the array and add their sum to the array. The cost of this operation will be the sum of the two elements. Print the minimum cost till the size of the array does not become 1.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.


Output Format

For each test case, print the minimum cost till the size of the array does not become 1.


Constraints

1≤ T ≤ 106

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.


Sample Input 1

3
4
3 1 4 2
3
1 1 1
4
2 3 1 3

Sample Output 1

19
5
18

Note

For the first test case, take 5 and 6 to get sum (5+6) = 11

For the second test case, take 1 and 1, array becomes [2, 1] and then take 2 and 1 to get sum (1+1) + (2+1) = 5

For the third test case, take 1 and 2, array becomes [3, 3, 3] and then take 3 and 3, array becomes [6, 3] and then take 6 and 3 to get sum (1+2) + (3+3) + (6+3) = 18*/

// Approach: In order to minimize the sum, the elements that get chosen at every step must the minimum elements from the list. In order to do that efficiently, a priority queue can be used. At every step, while there is more than a single element in the list, choose the minimum and the second minimum, remove them from the list add their sum to the list after updating the running sum.

#include <bits/stdc++.h>
using namespace std;
int work(){
    int n;
    cin>>n;
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < n; i++){
        int val;
        cin>>val;
        pq.push(val);
    }
    int ans=0;
    while(pq.size()>1){
        int p = pq.top();
        pq.pop();
        int q = pq.top();
        pq.pop();
        ans = ans +(p+q);
        pq.push(p+q);
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