#include <iostream>
#include <stack>

using namespace std;

bool query(const int length) {
    int current = 1, require;
    stack<int> station;
    station.push(0);
    
    for (int i = 0; i < length; ++i) {
        cin >> require;
        while (station.top() != require && current <= length) {
            station.push(current++);
        }

        if (station.top() != require) continue;

        station.pop(); 
    }

    return (station.top() == 0);
}


int main() {
    int testData, length;
    cin >> testData;

    while (testData--) {
        cin >> length;
        cout << (query(length) ? "Yes\n" : "No\n");
    }
}
