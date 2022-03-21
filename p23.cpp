#include <stack>
#include <vector>

using namespace std;

void solve(int N, int order[]) {
    stack<int> stationA, stationB;
    vector<int> at(N + 1, 1);
    for (int i = 1; i <= N; ++i) {
        push_train();
        stationA.push(i);
    }

    for (int i = 0; i < N; ++i) {
        if (at[order[i]] == 1) {
            while (stationB.empty() || stationB.top() != order[i]) {
                at[stationA.top()] = 2;
                stationB.push(stationA.top()); 
                stationA.pop();
                move_station_1_to_2();
            }
        } else if (at[order[i]] == 2) {
            while (stationB.top() != order[i]) {
                at[stationB.top()] = 1;
                stationA.push(stationB.top()); 
                stationB.pop();
                move_station_2_to_1();
            }
        }
        at[stationB.top()] = 0;
        pop_train();
        stationB.pop();
    }
}
