#include <bits/stdc++.h>
using namespace std;
int work(int n){
   int mul;
    long long int product = 1;
        for (int i = 0; i < N; i++) {
            int digit;
            cin >> digit;
            product = (product * digit) % MOD;
        }

        cout << product << endl;
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