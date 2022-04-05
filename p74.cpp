#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    unsigned int testdata, brickCount, nextBrick, currentBrick, length;
    bool findTaller;
    cin >> testdata;

    while (testdata--) {
        findTaller = 0;
        length = 1;
        cin >> brickCount;
        if (brickCount < 3) {
            while (brickCount--) cin >> nextBrick;
            cout << 0 << '\n';
            continue;
        }

        cin >> currentBrick;
        while (--brickCount) {
            cin >> nextBrick;
            if (currentBrick == nextBrick) continue;

            if (currentBrick > nextBrick ^ findTaller) {
                length++;
                findTaller = !findTaller;
            }
            currentBrick = nextBrick;
        }

        cout << length - findTaller << '\n';
    }
}