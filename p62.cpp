#include <iostream>

using namespace std;

int grid[9][9];
bool hasAnswer;

void print() {
    for (int i = 0; i < 81; i++) {
        cout << grid[i/9][i%9];
    }
    cout << '\n';
}

bool check(int pos) {
    int x = pos / 9, y = pos % 9;

    for (int i = 0; i < 9; i++) {
        if (grid[i][y] == grid[x][y] && i != x) return false;
        if (grid[x][i] == grid[x][y] && i != y) return false;
    }

    int bX = x / 3 * 3, bY = y / 3 * 3;
    for (int i = bX; i < bX + 3; i++) {
        for (int j = bY; j < bY + 3; j++) {
            if (grid[i][j] == grid[x][y] && (i != x || j != y)) return false;
        }
    }

    return true;
}

void solve(int pos) {
    if (hasAnswer) return;
    if (pos == 81) {
        hasAnswer = 1;
        print();
        return;
    }

    if (grid[pos/9][pos%9]) {
        solve(pos + 1);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        grid[pos/9][pos%9] = i;
        if (check(pos)) solve(pos + 1);
    }
    grid[pos/9][pos%9] = 0;
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int gameCount;
    cin >> gameCount;
    string game;
    while (gameCount--) {
        cin >> game;
        hasAnswer = false;
        bool flag = true;
        for (int i = 0; i < 81; i++) grid[i/9][i%9] = (game[i] != '.' ? game[i] - '0' : 0);
        for (int i = 0; i < 81 && flag; i++) {
            if (grid[i/9][i%9]) {
                if (check(i)) continue;
                flag = false;
            }
        }
        if (!flag) {
            cout << "No solution.\n";
            continue;
        }
        
        solve(0);
        if (!hasAnswer) cout << "No solution.\n";
    }
    
}