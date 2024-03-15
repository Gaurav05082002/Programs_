// Registration AZ101

// Time-Limit: 1 sec Score: 0/100
// Difficulty : 
//  Memory: 256 MB Accepted Submissions: 100
// Description

// Being the site administrator, you need to register the people on the website. A person registers with his name, S. If the name does not occur in the records, the person gets registered on the website and “OK” is shown. Otherwise, if the record already exists, print the name along with the number of times the person has registered on the website before, without any spaces.


// Input Format

// The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

// The first line of each test case contains one integer N - the number of people who register. 

// Each of the next N lines contains a string S - the name in lower case alphabets.


// Output Format

// For each test case, print “OK” if the person registers for the first time. Otherwise, print the name along with the number of times the person has registered on the website before, without any spaces.


// Constraints

// 1≤ T ≤ 105

// 1≤ N ≤ 105

// 1≤ |S| ≤ 30

// It is guaranteed that the sum of N over all test cases does not exceed 106.


// Sample Input 1

// 2
// 4
// harry
// ron
// harry
// hermione
// 3
// abc
// abc
// abc

// Sample Output 1

// OK
// OK
// harry1
// OK
// OK
// abc1
// abc2
 
 #include <bits/stdc++.h>
 using namespace std;
 map<string , int > m;
 int work(int n){
     if( n ==1){
        string s;
        cin>>s;
        if(m[s] == 0){
            m[s]++;
            cout<<"OK"<<endl;
        }
        else{
            cout<<s<<m[s]<<endl;
            m[s]++;
        }
     }
     return 0;
 }

 int main() {
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
        work(n);
    }
    return 0;
 }

