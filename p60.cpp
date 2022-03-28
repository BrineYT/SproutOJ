#include <iostream>
#include <algorithm>

using namespace std;

int slow, fast, cost, regen, energy, route, timeLimit, farthest;

int bestTime();
int distance(const int, const int);
int bestDistance(const int);


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> slow >> fast >> cost >> regen;
    cin >> energy >> route >> timeLimit;

    farthest = bestDistance(timeLimit);
    cout << (farthest >= route ? "Yes\n" : "No\n");
    cout << (farthest >= route ? bestTime() : farthest) << '\n';
}


int distance(const int wait, const int total) {
    int gasTime = (energy + regen * wait) / cost;
    return (min(gasTime, total - wait) * (fast - slow) + (total - wait) * slow);
}

int bestDistance(const int time) {
    int best = 0;
    for (int i = 0; i <= time; i++) best = max(best, distance(i, time));
    return best;
}

int bestTime() {
    int l = 0, m, r = timeLimit;
    while (r - l > 1) {
        m = l + r >> 1;
        (bestDistance(m) >= route ? r : l) = m;
    }
    return r;
}