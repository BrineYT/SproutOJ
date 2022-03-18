#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int query;
    cin >> query;
    
    int command, number;

    while (query--) {
        cin >> command;
        if (command & 1) {
            cin >> number;
            q.push(number);
        } else {
            if (q.empty()) {
                cout << "empty!\n";
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
    }
}