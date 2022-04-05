#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testdata;
    cin >> testdata;

    while (testdata--) {
        long long numberCount, temp;
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long> > smallest;

        cin >> numberCount;
        while (numberCount--) {
            cin >> temp;
            smallest.push(temp);
        }

        while (smallest.size() != 1) {
            temp = smallest.top();
            smallest.pop();
            temp += smallest.top();
            smallest.pop();
            sum += temp;
            smallest.push(temp);
        }

        cout << sum << '\n';
    }
}