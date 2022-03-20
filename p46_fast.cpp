#include <iostream>
#include <algorithm>

using namespace std;

typedef char int8;

const int8 R = 1 << 0;
const int8 Y = 1 << 1;
const int8 B = 1 << 2;

struct Borders {
    short l, r, u, d;

    int area() {
        if (r - l < 0 || d - u < 0) return 0;
        return (r - l) * (d - u);
    }

    Borders operator| (const Borders anotherColor) {
        Borders result(0, 0);
        result.l = max(this->l, anotherColor.l);
        result.r = min(this->r, anotherColor.r);
        result.u = max(this->u, anotherColor.u);
        result.d = min(this->d, anotherColor.d);
        return result;
    }

    void update(const int n) {
        if (l) l--;
        if (r < n) r++;
        if (u) u--;
        if (d < n) d++;
    }

    Borders(short left, short up): l(left), r(left + 1), u(up), d(up + 1) {}
};

int8 toId[90];

void initialize();
int evaluate();

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    initialize();

    short testdata;
    cin >> testdata;

    while (testdata--) {
        cout << evaluate() << '\n';
    }
}

void initialize() {
    toId['R'] = 1;
    toId['Y'] = 2;
    toId['O'] = 3;
    toId['B'] = 4;
    toId['P'] = 5;
    toId['G'] = 6;
    toId['D'] = 7;
}

int evaluate() {
    short length;
    cin >> length;

    char color;
    short x, y;
    Borders* primaryColor[5] = {nullptr};

    for (short i = 0; i < 3; i++) {
        cin >> color >> x >> y;
        primaryColor[toId[color]] = new Borders(x, y);
    }

    cin >> color;
    int maximumArea = 0;
    int area[8] = {0};

    while (true) {
        area[R] = primaryColor[R]->area();
        area[Y] = primaryColor[Y]->area();
        area[B] = primaryColor[B]->area();
        area[R | Y] = (*primaryColor[R] | *primaryColor[Y]).area();
        area[Y | B] = (*primaryColor[Y] | *primaryColor[B]).area();
        area[B | R] = (*primaryColor[B] | *primaryColor[R]).area();
        area[R | Y | B] = (*primaryColor[R] | *primaryColor[Y] | *primaryColor[B]).area();

        area[R | Y] -= area[R | Y | B]; 
        area[Y | B] -= area[R | Y | B];
        area[B | R] -= area[R | Y | B];
        area[R] -= area[R | Y] + area[B | R] + area[R | Y | B];
        area[Y] -= area[R | Y] + area[Y | B] + area[R | Y | B];
        area[B] -= area[Y | B] + area[B | R] + area[R | Y | B];

        maximumArea = max(maximumArea, area[toId[color]]);

        if (area[R | Y | B] == length * length) break;

        for (short i = 0; i < 3; i++) primaryColor[1 << i]->update(length);
    }

    return maximumArea;
}