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



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n + 1; j++) {
            if (j == n+1) cout << "@";
            else cout << "  ";
        }
        cout << endl;
    }

    return 0;
}


// /// python code for the same pattern

// n = 3
// width = 2 * n + 1

// # Top 3 rows
// for row in range(3):
//     if row == 0:  # First row
//         print("* " * n + "  " * n + "* " * n)
//     elif row == 1:  # Second row
//         print("  " * (n - 1) + "* " + "  " * n + "* ")
//     else:  # Third row
//         print("  " * (n - 1) + "* " * (2 * n - 1))

// # Rows with @
// for i in range(n):
//     for j in range(2 * n + 1):
//         if j == n + 1:
//             print("@ ", end="")
//         else:
//             print("  ", end="")
//     print()



