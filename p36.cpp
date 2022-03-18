#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    stack<int> s;
    int query;
    cin >> query;
    
    int command, number;

    while (query--) {
        cin >> command;
        if (command & 1) {
            cin >> number;
            s.push(number);
        } else {
            if (s.empty()) {
                cout << "empty!\n";
            } else {
                cout << s.top() << '\n';
                s.pop();
            }
        }
    }
}