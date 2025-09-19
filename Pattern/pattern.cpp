#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for (int i = 0; i < 2 * n; i++) {
        // Left border '@' or space
        if (i < n) {
            cout << "@";
        } else {
            cout << " ";
        }

        // Middle part (stars and spaces)
        if (i >= n / 2 && i < n + n / 2) {
            cout << string((n - 1) * (i - n / 2), ' '); // left spaces
            cout << string(n, '*');                     // stars
            cout << string(((n * (n - 1)) - (n - 1)) - ((n - 1) * (i - n / 2)), ' '); // right spaces
        } else {
            cout << string(n * (n - 1) + 1, ' ');
        }

        // Right border '@' or space
        if (i >= n - 1) {
            cout << "@";
        } else {
            cout << " ";
        }

        cout << "\n"; // move to next line
    }

    return 0;
}
