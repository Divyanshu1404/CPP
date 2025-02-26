///Q:Sort a stack using a temp stack

#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& s) {
    stack<int> tempStack;
    while (!s.empty()) {
        int currElement = s.top();
        s.pop();
        while (!tempStack.empty() && tempStack.top() > currElement) {
            s.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(currElement);
    }
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main() {
    stack<int> s;
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);
    cout << "Original Stack:" << endl;
    printStack(s);
    sortStack(s);
    cout << "Sorted Stack:" << endl;
    printStack(s);
    return 0;
}
