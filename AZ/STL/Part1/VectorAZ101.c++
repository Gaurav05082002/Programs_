#include <iostream>
#include <vector> // Include vector header
using namespace std;

   vector<int> v;
int function(int x) { // Pass vector by reference to modify it
  
    // Add
    if (x == 1) {
        int y;
        cin >> y;
        v.push_back(y); // Add semicolon here
    }
    // Remove
    if (x == 2) {
        if (!v.empty()) // Check if vector is not empty before pop
            v.pop_back(); // Use pop_back() to remove the last element
    }
    // Print xth element
    if (x == 3) {
        int z;
        cin >> z; // Read the index to print
        if (z > 0 && z <= v.size()) // Check if index is valid
            cout << v[z - 1] << endl; // Access the element using index - 1
    }
    // Remove all elements
    if (x == 4) {
        v.clear(); // Use clear() to remove all elements
    }
    return 0; // Return an int value
}

int main() {
    int t;
    cin >> t;
    while (t--) {
       int x;
    cin >> x;
        function(x);
    }
    return 0;
}
