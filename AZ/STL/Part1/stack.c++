#include <iostream>
#include <stack>

using namespace std;

// Function to print the xth element of the stack without disturbing it
void printXthElement(stack<int> s, int x) {
    // Temporary stack to store elements while iterating
    stack<int> tempStack;
    int count = 0;

    // Iterate through the stack and copy elements to the temporary stack until reaching the xth element
    while (!s.empty()) {
        if (count == x - 1) {
            cout << "The xth element of the stack is: " << s.top() << endl;
            return;
        }
        tempStack.push(s.top());
        s.pop();
        count++;
    }

    // If the stack doesn't have enough elements
    cout << "Error: Stack doesn't have enough elements." << endl;
}

int main() {
    // Creating a stack
    stack<int> s;

    // Entering elements into the stack
    cout << "Enter elements into the stack (enter -1 to stop):" << endl;
    int element;
    cin >> element;
    while (element != -1) {
        s.push(element);
        cin >> element;
    }

    // Remove the last element from the stack
    if (!s.empty()) {
        cout << "Removing last element from the stack: " << s.top() << endl;
        s.pop();
    } else {
        cout << "Error: Stack is empty, cannot remove last element." << endl;
    }

    // Print the xth element of the stack
    int x;
    cout << "Enter the position (x) of the element you want to print: ";
    cin >> x;
    printXthElement(s, x);

    // Clear all elements from the stack
    cout << "Clearing all elements from the stack..." << endl;
    while (!s.empty()) {
        s.pop();
    }

    cout << "Stack is now empty." << endl;

    return 0;
}
