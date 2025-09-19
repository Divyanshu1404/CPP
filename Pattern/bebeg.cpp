#include <iostream>
using namespace std;

int main() {
    int n = 3; 
    
    int width = 2 * n+1; 
    for (int i = 0; i < n; i++) cout << "* ";
    for (int i = 0; i < n; i++) cout << "  "; 
    for (int i = 0; i < n; i++) cout << "* ";
    cout << endl;

    for (int i = 0; i < n - 1; i++) cout << "  "; 
    cout << "* ";
    
    for (int i = 0; i < n; i++) cout << "  "; 
    cout << "* ";
    cout << endl;

    for (int i = 0; i < n - 1; i++) cout << "  "; 
    for (int i = 0; i < 2 * n-1; i++) cout << "* ";
    cout << endl;

/// for the last @

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            if (j == n+1) cout << "@";
            else cout << "  ";
        }
        cout << endl;
    }

    return 0;
}

