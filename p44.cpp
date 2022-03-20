#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<string> maze;

struct coords {
    int x, y, distance;
};

void evaluate() {
    int height, width;
    cin >> height >> width;
    maze.resize(height);

    for (string &n: maze) cin >> n;

    int xCat = 0, yCat = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 'K') {
                xCat = i;
                yCat = j;
                maze[i][j] = '#';
            }
        }
    }

    queue<coords> move;
    move.push({xCat, yCat, 0});

    while (!move.empty()) {
        int& x = move.front().x;
        int& y = move.front().y;
        move.front().distance++;
        for (int i = 0; i < 4; i++) {
            if (maze[x + dx[i]][y + dy[i]] == '#') continue;

            if (maze[x + dx[i]][y + dy[i]] == '@') {
                cout << move.front().distance << '\n';
                return;
            }

            maze[x + dx[i]][y + dy[i]] = '#';
            move.push({x + dx[i], y + dy[i], move.front().distance});
        }
        move.pop();
    }

    cout << "= =\"\n";
}

int main() {
    int testdata;
    cin >> testdata;
    while (testdata--) {
        evaluate();
    }
}