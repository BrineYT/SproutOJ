#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dfs(int, vector<vector<int> >&, vector<int>&);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int testdata;
    cin >> testdata;

    int point, p1, p2, minIndex;
    while (testdata--) {
        cin >> point;

        vector<vector<int> > edge(point, vector<int>{});
        vector<int> maxSubtree(point, 0);

        for (int i = 1; i < point; i++) {
            cin >> p1 >> p2;
            edge[p1].push_back(p2);
            edge[p2].push_back(p1);
        }

        dfs(0, edge, maxSubtree);

        minIndex = 0;
        for (int i = 0; i < point; i++) {
            if (maxSubtree[i] < maxSubtree[minIndex]) minIndex = i;
        }

        cout << minIndex << '\n';
    }
}

int dfs(int now, vector<vector<int> >& edge, vector<int>& value) {
    int pointBefore, pointAfter = 0, largest = 0, subTree = 0;
    value[now] = -1;
    for (auto& n : edge[now]) {
        if (value[n]) continue;

        subTree = dfs(n, edge, value);
        pointAfter += subTree;
        largest = max(largest, subTree);
    }

    pointBefore = edge.size() - pointAfter - 1;

    value[now] = max(pointBefore, largest);

    return pointAfter + 1;
}