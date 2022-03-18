#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long evaluate(const int);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testData, length;
    cin >> testData;

    while (testData--) {
        cin >> length;

        cout << evaluate(length) << '\n';
    }
}


long long evaluate(const int length) {
    long long total = 0;
    unsigned int input, less, equal, size = 1;
    vector<unsigned int> available{2147483648};
    vector<unsigned int>::reverse_iterator it;

    for (int i = 0; i < length; i++) {
        less = equal = 0;
        cin >> input;
        it = available.rbegin();

        less = lower_bound(available.rbegin(), available.rend(), input) - available.rbegin();
        equal = upper_bound(available.rbegin(), available.rend(), input) - available.rbegin();

        total += (equal + 1 != size);
        total += equal;
        size -= less - 1;
        available.resize(size);
        *available.rbegin() = input;
    }

    return total;
}

