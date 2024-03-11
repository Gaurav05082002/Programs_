#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Creating a queue
    queue<int> q;

    // Adding elements to the queue
    for (int i = 1; i <= 5; ++i) {
        q.push(i);
    }

    // Check if the queue is empty
    if (!q.empty()) {
        cout << "Queue is not empty. Making it empty..." << endl;

        // Remove all elements from the queue
        while (!q.empty()) {
            q.pop();
        }

        cout << "Queue is now empty." << endl;
    } else {
        cout << "Queue is already empty." << endl;
    }

    return 0;
}
