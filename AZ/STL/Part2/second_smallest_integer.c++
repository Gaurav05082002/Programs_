//second smallest integer in array 
#include <bits/stdc++.h>
using namespace std;
int main() {

     int n;
     cin>>n;
     vector<int> arr(n);
     for (int i = 0; i < n; i++)
     {
           cin>>arr[i];

     }
     int s = 1e9;
     int a = 1e9;
     for (int i = 0; i < n; i++)
     {
        if(arr[i] < s){
            s = arr[i];
        }
        if(arr[i] > s && arr[i] < a){
            a = arr[i];
        }
     }
     
     cout<<a<<endl;
     

    return 0;
}