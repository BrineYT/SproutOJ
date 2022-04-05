#include <bits/stdc++.h>

using namespace std;

int evaluate(const int& people) {
    vector< pair<int, int> > customer(people);
    for (auto& [eatTime, cookTime]: customer) cin >> cookTime >> eatTime;

    sort(customer.rbegin(), customer.rend());
    int currentCookTime = 0, endTime = 0;
    for (const auto& [eatTime, cookTime]: customer) {
        currentCookTime += cookTime;
        endTime = max(endTime, currentCookTime + eatTime);
    }

    return endTime;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testdata, people;
    cin >> testdata;

    while (testdata--) {
        cin >> people;
        cout << evaluate(people) << '\n';
    }
}