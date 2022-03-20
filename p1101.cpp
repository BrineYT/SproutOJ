#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool flag;
bitset<100000> tag, visited;
vector< vector<int> > edgeBetween;

bool isBipartite(const int, const int);
bool dfs(const int);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testdata, vertex, edge;
    cin >> testdata;

    while (cin >> vertex >> edge) {
        cout << (isBipartite(vertex, edge) ? "NORMAL.\n" : "RAINBOW.\n");
    }
}

bool isBipartite(const int vertex, const int edge) {
    edgeBetween.resize(vertex);
    for (int i = 0; i < vertex; i++) {
        tag.reset(i);
        visited.reset(i);
        edgeBetween.clear();
    }

    int a, b;
    for (int i = 0; i < edge; i++) {
        cin >> a >> b;
        edgeBetween[a].push_back(b);
        edgeBetween[b].push_back(a);
    }

    for (int i = 0; i < vertex; i++) {
        if (visited[i]) continue;

        if (!dfs(i)) return false;
    }

    return true;
}

bool dfs(const int i) {
    for (const int &n: edgeBetween[i]) {
        if (visited[n]) {
            if (tag[n] == tag[i]) return false;

            continue;
        }

        visited[n] = true;
        tag[n] = !tag[i];
        if (!dfs(n)) return false;
    }

    return true;
}