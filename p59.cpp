#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int action;
    cin >> action;

    int command, content;
    priority_queue< int, vector<int>, greater<int> > pq;
    while (action--) {
        cin >> command;
        if (command & 1) {
            cin >> content;
            pq.push(content);
        } else {
            if (pq.empty()) {
                cout << "empty!\n";
                continue;
            }

            cout << pq.top() << '\n';
            pq.pop();
        }
    }
}