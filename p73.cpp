#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long evaluate(const int, const int);

int main() {
    ios_base::sync_with_stdio(0);

    int testdata;
    cin >> testdata;

    int character, people;
    while (testdata--) {
        cin >> character >> people;
        cout << evaluate(character, people) << '\n';
    }
}


long long evaluate(const int character, const int people) {
    long long l = 0, r = 0, m;
    vector<long long> timeRequired(character);
    for (auto &n: timeRequired) {
        cin >> n;
        l = max(l, n);
        r += n;
    }

    l--;
    long long current, total;
    while (r - l > 1) {
        m = l + r >> 1;
        current = total = 0;

        for (auto &n: timeRequired) {
            if (total > people) break;

            if (current + n > m) {
                current = n;
                total++;
                continue;
            }

            current += n;
        }

        (total >= people ? l : r) = m;
    }
    
    return r;
}