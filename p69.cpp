// 69 nice

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct horse {
    long long speed = 0, growthRate = 0;

    void grow(const int time) {
        speed += growthRate * time;
    }
};

bool speedCompare (horse &a, horse &b) {
    return a.speed < b.speed; 
}

bool possible(const int, vector<horse>, vector<horse>, const int);

int main() {
    int testdata;
    cin >> testdata;
    
    int horseCount, winStandard;
    vector<horse> self, opponent;
    while (testdata--) {
        cin >> horseCount >> winStandard;

        self.resize(horseCount);
        opponent.resize(horseCount);
        for (auto &n: self) cin >> n.speed >> n.growthRate;
        for (auto &n: opponent) cin >> n.speed;
        sort(opponent.begin(), opponent.end(), speedCompare);

        int l = -1, m, r = 1e9;
        while (r - l > 1) {
            m = (l + r) / 2;
            // cout << "test " << m << '\n';
            (possible(m, self, opponent, winStandard) ? r : l) = m;
        }

        cout << (r >= 1e9 ? -1 : r) << '\n';
    }
}


bool possible(const int m, vector<horse> my, vector<horse> his, const int win) {
    for (auto &n: my) n.grow(m);
    sort(my.rbegin(), my.rend(), speedCompare);

    auto myIt = my.begin() + win - 1;
    auto hisIt = his.begin();
    for (int i = 0; i < win; i++) {
        if ((*myIt).speed <= (*hisIt).speed) return false;
        myIt--;
        hisIt++;
    }
    return true;
}