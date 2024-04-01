/*Description

Implement a stack that supports the following operations.

push x -- Push element x onto stack.
pop -- Remove the element on top of the stack, if the stack is non-empty. Otherwise do nothing.
top -- Print the top element, if the stack is non-empty. Otherwise, print -1.
getMin -- Print the minimum element in the stack, if the stack is non-empty. Otherwise, print -1.
Initially, the stack is empty.


Input Format

The first line of input contains Q - the number of queries.
Each of next line contains input in one of the four formats mentioned in the problem statement.


Output Format

Print the answer for the top and getMin operations.


Constraints

1 ≤ Q ≤ 106
0 ≤ x ≤ 109


Sample Input 1

11
push 1
push 3
top
getMin
pop
top
getMin
pop
pop
top
getMin

Sample Output 1

3
1
1
1
-1
-1*/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> dataStack; // main stack to store elements
    stack<int> minStack; // auxiliary stack to store minimum elements

public:
    MinStack() {}

    void push(int x) {
        dataStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!dataStack.empty()) {
            if (dataStack.top() == minStack.top()) {
                minStack.pop();
            }
            dataStack.pop();
        }
    }

    int top() {
        if (!dataStack.empty()) {
            return dataStack.top();
        }
        return -1;
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin >> q;

    MinStack s;

    while(q--) {
        string op;
        cin >> op;

        if(op == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if(op == "pop") {
            s.pop();
        }
        else if(op == "top") {
            cout << s.top() << "\n";
        }
        else if(op == "getMin") {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}
