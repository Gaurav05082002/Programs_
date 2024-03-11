#include <bits/stdc++.h>
using namespace std;

stack<int> a;
stack<int> b;

void fun(int n) {
    if (n == 1) {
        int x;
        cin >> x;
        a.push(x);
    } else if (n == 2) {
        while (!a.empty()) {
            int z = a.top();
            a.pop();
            if (a.empty()) {
                cout << z << endl;
            } else {
                b.push(z);
            }
        }
        while (!b.empty()) {
            int z = b.top();
            b.pop();
            a.push(z);
        }
    } else if (n == 3) {
        if (a.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << a.top() << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fun(n);
    }
    return 0;
}
