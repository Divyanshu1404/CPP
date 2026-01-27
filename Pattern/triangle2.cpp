#include <iostream>
using namespace std;

int main() {
    int i, j, space;

    for(i = 5; i >= 1; i -= 2) {
        for(space = 0; space < (5 - i) / 2; space++)
            cout << " ";

        for(j = 0; j < i; j++)
            cout << "*";

        cout << "\n";
    }

    for(i = 3; i <= 5; i += 2) {
        for(space = 0; space < (5 - i) / 2; space++)
            cout << " ";

        for(j = 0; j < i; j++)
            cout << "*";

        cout << "\n";
    }

    return 0;
}