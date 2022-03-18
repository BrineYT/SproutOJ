#include <iostream>
#include <climits>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int commandCount;
    cin >> commandCount;

    set<int> numbers;
    numbers.insert(INT32_MAX);
    numbers.insert(INT32_MIN);

    string command;
    int target;
    while (commandCount--) {
        cin >> command >> target;
        if (command[0] == 'i') {
            numbers.insert(target);
        } else if (command[0] == 'd') {
            numbers.erase(target);
        } else {
            int right = *numbers.lower_bound(target);
            int left = *prev(numbers.lower_bound(target));
            if (target - left == right - target) {
                cout << left << ' ' << right << '\n';
            } else {
                cout << (target - left < right - target ? left : right) << '\n';
            }
        }
    }
}