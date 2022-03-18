#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> glass;
    int testData, matter;
    bool flag = true;
    cin >> testData;
    while (testData--) {
        cin >> matter;
        if (matter < 0) {
            if (glass.empty() || *glass.rbegin() != -matter) {
                flag = false;
                break;
            } else {
                glass.pop_back();
            }
            continue;
        }

        glass.push_back(matter);
        // for (auto n: glass) cout << n << ' ';
        // cout << '\n';
    }

    cout << (flag && glass.empty() ? "weed\n" : "lose light light\n");
}