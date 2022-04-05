#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testdata;
    cin >> testdata;

    int arr[7];
    int sum;
    while (testdata--) {
        for (int i = 1; i <= 6; i++) cin >> arr[i];

        sum = arr[6] + arr[5] + arr[4] + arr[3] / 4;
        arr[2] -= arr[4] * 5;
        arr[1] -= arr[5] * 11;

        arr[3] %= 4;
        if (arr[3]) {
            sum++;
            arr[2] -= 7 - arr[3] * 2;
            arr[1] -= 8 - arr[3];
        }

        if (arr[2] < 0) arr[1] += arr[2] * 4;
        if (arr[2] > 0) {
            sum += arr[2] / 9 + (arr[2] % 9 != 0);
            arr[2] %= 9;
            arr[1] -= 36 - arr[2] * 4;
        }

        if (arr[1] > 0) sum += arr[1] / 36 + (arr[1] % 36 != 0);
        
        cout << sum << '\n';
    }
}