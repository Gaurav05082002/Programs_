/*Molecular Formula

Time-Limit: 1 sec Score: 0/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You've been given chemical formula of a compound. Your task is to print the count of each atom.
The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.
Two formulas concatenated together to produce another formula. For example, H2O2He3Mg4 is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

It's guaranteed that the total count of each individual atom is within INT_MAX.


Input Format

The only line of input contains a string S representing the chemical formula of a compound.


Output Format

Print the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.


Constraints

1 ≤ |S| ≤ 103


Sample Input 1

Mg(OH)2

Sample Output 1

H2MgO2

Sample Input 2

K4(ON(SO3)2)2

Sample Output 2

K4N2O14S4

Sample Input 3

(Ti34)10

Sample Output 3

Ti340*/

#include <bits/stdc++.h>
#include <string>
using namespace std;
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}
int myStoi(const string& str) {
    int result = 0;
    for (char const &c : str) {
        if (c < '0' || c > '9') {
            cerr << "Error: Invalid input string. Only positive integers are allowed." << endl;
            return 0; // or throw an exception based on your error handling preference
        }
        result = result * 10 + (c - '0');
    }
    return result;
}

int work(){
    string s;
    cin>>s;
    map<char,int>m;
    stack<int> q;
    stack<int> b;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == ')'){
            string l="";
            if(isDigit(s[i++]) != 1){
                
                q.push(1);
                // cout<<"q pushing"<<1<<endl;
            }else{
                // K4(ON(SO3)62)2
                i++;
                while(i < s.size() && isDigit(s[i])){
                    l=l+s[i];
                    i++;
                }
                i--;
                //  cout<<"q pushinggg"<<myStoi(l)<<endl;
                q.push(myStoi(l));
            }
        }
    }
    int mul = 1;
    for (int i = 0; i < s.size(); i++)
    {
       
        if(s[i] == '('){
            int z = q.top();
            b.push(z);
            q.pop();
            mul = mul*z;
        }
        else if(s[i] == ')'){
            int u = b.top();
            b.pop();
            mul = mul/u;
        }
        else{
               string l="";
               char rea = s[i];
            if(isDigit(s[i++]) != 1){
                if(m.find(s[i]) != m.end()){
                     m[s[i]] = m[s[i]] + 1*mul;
                }
                else{ 
                     m[s[i]] =  1*mul;
                }
                  
            }else{
                // K4(ON(SO3)62)2
                i++;
                while(i<s.size() && isDigit(s[i])){
                    l=l+s[i];
                    i++;
                }
                i--;
                if(m.find(rea) != m.end()){
                     m[rea] = m[rea] + myStoi(l)*mul;
                }
                else{
                      m[rea] =  myStoi(l)*mul;
                }
                
            }
        }
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
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