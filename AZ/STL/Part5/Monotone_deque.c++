#include <iostream>
#include <deque>

using namespace std;

struct monotone_deque {
    deque<int> dq;

    void insert(int x) {
        while (!dq.empty() && dq.back() < x) {
            dq.pop_back();
        }
        dq.push_back(x);
    }

    void remove(int x) {
        if (!dq.empty() && dq.front() == x) {
            dq.pop_front();
        }
    }

    int getMin() {
        return dq.front();
    }
};

int main() {
    monotone_deque md;
    md.insert(5);
    md.insert(3);
    md.insert(7);
    cout << "Minimum element in deque: " << md.getMin() << endl;
    md.remove(3);
    cout << "Minimum element in deque after removal: " << md.getMin() << endl;
    return 0;
}
