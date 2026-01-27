#include <iostream>
using namespace std;

void printSpaces(int count) {
    for (int i = 0; i < count; i++)
        cout << " ";
}

void printStars(int count) {
    for (int i = 0; i < count; i++)
        cout << "*";
}

void printButterfly(int n) {
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        printStars(2 * i - 1);
        printSpaces(2 * (n - i) + 1);
        printStars(2 * i - 1);
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    printButterfly(n);
    
    return 0;
}