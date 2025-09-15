#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int spaces = 2 * n - 1;
    int stars = 0;

    for (int i = 1; i <= 2 * n - 1; i++) {
        // Upper half
        if (i <= n) {
            spaces =spaces - 2;
            stars++;
        }
        // Lower half
        else {
            spaces += 2;
            stars--;
        }

        // Left stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        // Middle spaces
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }

        // Right stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        cout << "\n";
    }

    return 0;
}
