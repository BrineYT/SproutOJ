#include <iostream>
#include <vector>

using namespace std;

void evaluate(int, int);

int main() {
    ios_base::sync_with_stdio(0);

    int testdata, boxCount, actionCount;
    cin >> testdata;

    while (testdata--) {
        cin >> boxCount >> actionCount;
        evaluate(boxCount, actionCount);
    }
}

void evaluate(int box, int action) {
    vector<int> boxInside(box + 1, 1);
    while (action--) {

    }
    int query, qId;
    cin >> query;
    while (query--) {
        cin >> qId;
        cout << boxInside[qId] << '\n';
    } 
}