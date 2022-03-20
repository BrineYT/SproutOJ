#include <iostream>
#include <queue>
#include <algorithm>

#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;

typedef char int8;

struct coords {
    short x, y;
    int8 color;
    short time = 0;
};

int8 toId[90];
short LENGTH;
short dx[] = {0, 0,-1,-1,-1, 1, 1, 1};
short dy[] = {1,-1, 1, 0,-1, 1, 0,-1};

void initializeId();
int evaluate();

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("error.txt", "w", stderr);
    initializeId();

    int testdata;
    cin >> testdata;

    while (testdata--) {
        cout << evaluate() << '\n';
    }
}


void initializeId() {
    toId['W'] = 0;
    toId['R'] = 1;
    toId['Y'] = 2;
    toId['O'] = 3;
    toId['B'] = 4;
    toId['P'] = 5;
    toId['G'] = 6;
    toId['D'] = 7;
}

int evaluate() {
    cin >> LENGTH;
    int8 field[LENGTH + 2][LENGTH + 2];
    fill(field[0], field[0] + LENGTH + 2, 7);
    fill(field[LENGTH + 1], field[LENGTH + 1] + LENGTH + 2, 7);
    for (int i = 1; i <= LENGTH; i++) {
        fill(field[i], field[i] + LENGTH + 2, 0);
        field[i][0] = field[i][LENGTH + 1] = 7;
    }
    
    queue<coords> move;
    char color;
    short color_x, color_y;
    for (int i = 0; i < 3; i++) {
        cin >> color >> color_x >> color_y;
        field[++color_x][++color_y] = toId[color];
        move.push({color_x, color_y, toId[color]});
    }

    cin >> color;
    int8 target = toId[color];
    int maximumArea, currentArea;
    maximumArea = currentArea = (target == 1 || target == 2 || target == 4);
    // cerr << (int)target << '\n';

    int currentTime = 0;
    while (!move.empty()) {
        while (!move.empty() && currentTime >= move.front().time) {
            short& x = move.front().x;
            short& y = move.front().y;
            int8& now = move.front().color;
            // debug(x), debug(y);
            for (int i = 0; i < 8; i++) {
                int8& next = field[x + dx[i]][y + dy[i]];
                if ((next | now) == next) continue;

                // debug((int)next), debug((int)target);
                if (next == target) currentArea--;
                // debug(currentArea);
                next |= now;
                // debug((int)next), debug((int)target);
                if (next == target) currentArea++;
                // debug(currentArea);
                move.push({(short)(x + dx[i]), (short)(y + dy[i]), next, (short)((int)move.front().time + 1)});
            }
            // for (int k = 1; k < LENGTH + 1; k++) {
            //     for (int j = 1; j < LENGTH + 1; j++) {
            //         cerr << (int)field[k][j];
            //     }
            //     cerr << '\n';
            // }
            // cerr << '\n';
            move.pop();
        }
        // cerr << '(' << currentArea << ", " << move.size() << ")\n";
        maximumArea = max(maximumArea, currentArea);
        currentTime++;
    }

    return maximumArea;
}