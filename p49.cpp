#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

bitset<100001> isRoot;

void evaluate(int, int);
void dfs(int, vector<int>&, vector< vector<int> >&);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testdata, boxCount, actionCount;
    cin >> testdata;

    while (testdata--) {
        cin >> boxCount >> actionCount;
        for (int i = 1; i <= boxCount; ++i) isRoot[i] = 1;
        evaluate(boxCount, actionCount);
    }
}


void evaluate(int box, int action) {
    int big, small;
    vector< vector<int> > child(box + 1, vector<int>{});
    while (action--) {
        cin >> big >> small;
        isRoot[small] = 0;
        child[big].push_back(small);
    }

    vector<int> selfAndInside(box + 1, 1);

    for (int i = 1; i <= box; i++) {
        if (isRoot[i]) dfs(i, selfAndInside, child);
    }

    int query, qId;
    cin >> query;
    while (query--) {
        cin >> qId;
        cout << selfAndInside[qId] << '\n';
    }
}

void dfs(int start, vector<int> &count, vector< vector<int> > &child) {
    if (child[start].empty()) return;

    for (int n: child[start]) {
        dfs(n, count, child);
        count[start] += count[n];
    }
}