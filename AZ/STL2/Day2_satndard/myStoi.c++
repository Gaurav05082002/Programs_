#include <bits/stdc++.h>
using namespace std;
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
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int main(int argc, char const *argv[])
{ 
    cout<<myStoi("2")<<endl;
    cout<<isDigit("4")<<endl;
    
    return 0;
}
