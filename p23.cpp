#include <vector>
#include <algorithm>
// #include <iostream>

// using namespace std;

// void solve(int, int[]);
// void push_train() {cout << "Pull from start\n";};
// void move_station_1_to_2() {cout << "move A top to B top\n";};
// void move_station_2_to_1() {cout << "move B top to A top\n";};
// void pop_train() {cout << "Push to end\n";};
// void no_solution() {cout << "error has occured\n";};

// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; ++i) cin >> arr[i];
//     solve(n, arr);
// }

void solve(int N, int order[]) {
    std::vector<int> stationA(N);
    std::vector<int> stationB;
    for (int i = N; i > 0; --i) {
        push_train();
        stationA[N - i] = i;
    }
    // for (auto n: stationA) cout << n << ' ';
    // cout << "\n\n";

    for (int i = 0; i < N; ++i) {
        // target = order[i]
        // cout << order[i] << "\n\n";
        auto atA = find(stationA.begin(), stationA.end(), order[i]);
        auto atB = find(stationB.begin(), stationB.end(), order[i]);

        if (atA != stationA.end()) {
            while (stationB.empty() || *stationB.rbegin() != order[i]) {
                move_station_1_to_2();
                stationB.push_back(*stationA.rbegin());
                stationA.pop_back();
            }
            stationB.pop_back();
            pop_train();
        } else if (atB != stationB.end()) {
            while (*stationB.rbegin() != order[i]) {
                move_station_2_to_1();
                stationA.push_back(*stationB.rbegin());
                stationB.pop_back();
            }
            stationB.pop_back();
            pop_train();
        } else {
            no_solution();
        }
    }
}

