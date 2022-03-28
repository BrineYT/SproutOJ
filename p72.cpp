#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct func {
    double a, b, c;

    double of(const double t) {
        return a * (b - t) * (b - t) + c;
    }
};

using namespace std;

int main() {
    int testdata;
    cin >> testdata;

    int functionCount;
    vector<func> functionList;
    while (testdata--) {
        cin >> functionCount;
        functionList.resize(functionCount);
        for (auto &[a, b, c]: functionList) cin >> a >> b >> c;

        double l = 0, ml, mr, r = 300;
        double peak = 0, mlPeak, mrPeak;
        while (r - l > 1e-12) {
            ml = (l * 2 + r) / 3;
            mr = (l + r * 2) / 3;
            mlPeak = mrPeak = 0;

            for (auto f: functionList) {
                mlPeak = max(mlPeak, f.of(ml));
                mrPeak = max(mrPeak, f.of(mr));
            }

            if (mlPeak <= mrPeak) r = mr;
            if (mlPeak >= mrPeak) l = ml;

            peak = (mlPeak + mrPeak) / 2;
        }
        
        cout << fixed << setprecision(12) << peak << '\n';
    }
}