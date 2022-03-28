#include <iostream>
#include <vector>

using namespace std;

const int k = 6;
int numberCount;

vector<int> number;
vector<int> luckyNumber(6, 0);

void evaluate(const int, const int);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testdata;
    cin >> testdata;
    
    while (testdata--) {
        cin >> numberCount;
        number.resize(numberCount);
        for (int &n: number) cin >> n;

        evaluate(0, 0);
    }
}

void evaluate(const int now, const int nextNumber) {
    if (nextNumber == k) {
        for (int &n: luckyNumber) cout << n << " \n"[&n == &luckyNumber.back()];
        return;
    }

    for (int i = now; i < numberCount; i++) {
        luckyNumber[nextNumber] = number[i];
        if (numberCount - i < k - nextNumber) break;
        
        evaluate(i + 1, nextNumber + 1);
    }
    luckyNumber[nextNumber] = 0;
}