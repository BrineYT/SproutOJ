#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int evaluate(const int&, const int&);
bool possible(priority_queue< int, vector<int>, less<int> >, const vector<int>&, const int&);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testdata, boxCount, wishListLength;
    cin >> testdata;
    
    while (testdata--) {
        cin >> boxCount >> wishListLength;

        cout << evaluate(boxCount, wishListLength) << '\n';
    }
}

int evaluate(const int& boxCount, const int& listLength) {
    priority_queue< int, vector<int>, less<int> > box;
    vector<int> palm(listLength);

    int temp;
    for (int i = 0; i < boxCount; i++) {
        cin >> temp;
        box.push(temp);
    }
    for (int& n: palm) cin >> n;

    sort(palm.rbegin(), palm.rend());

    int l = 0, m, r = listLength + 1;
    while (r - l > 1) {
        m = l + r >> 1;
        (possible(box, palm, m) ? l : r) = m;
    }

    return l;
}

bool possible(priority_queue< int, vector<int>, less<int> > box,
              const vector<int>& palm, const int& picked) {
    int temp;
    for (auto it = palm.end() - picked; it != palm.end(); it++) {
        if (box.empty() || box.top() < *it) return 0;
        temp = box.top() - *it;
        box.pop();
        if (temp) box.push(temp);        
    }

    return 1;
}