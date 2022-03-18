#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int buildingCount;
    cin >> buildingCount;

    long long maxArea = 0;

    vector<long long> height(buildingCount + 1);
    vector<int> increasingHeight{};

    for (int i = 0; i < buildingCount; ++i) cin >> height[i];

    for (int i = 0; i <= buildingCount; ++i) {
        while (!increasingHeight.empty() && height[*increasingHeight.rbegin()] >= height[i]) {
            int last = *increasingHeight.rbegin();
            increasingHeight.pop_back();

            if (increasingHeight.empty()) {
                maxArea = max(maxArea, height[last] * i);
            } else {
                maxArea = max(maxArea, height[last] * (i - 1 - *increasingHeight.rbegin()));
            }
        }

        increasingHeight.push_back(i);
    }

    cout << maxArea << '\n';
}