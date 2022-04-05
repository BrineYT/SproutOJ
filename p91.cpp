#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testdata;
    cin >> testdata;

    long long child;
    while (testdata--) {
        vector<int> answer;
        cin >> child;
        if (child == 1) answer.push_back(1);
        for (int i = 9; i > 1; i--) {
            while (child % i == 0) {
                answer.push_back(i);
                child /= i;
            }
        }
        if (child != 1) {
            cout << "-1\n";
            continue;
        } 
        
        for (auto it = answer.rbegin(); it != answer.rend(); it++) cout << *it;
        cout << '\n';
    }
}