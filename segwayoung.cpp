#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() { // 30504
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> minmoney(N), inv(N);
    for (int i = 0; i < N; ++i) {
        cin >> minmoney[i].first;
        minmoney[i].second = i;
    }
    for (int i = 0; i < N; ++i) {
        cin >> inv[i].first;
        inv[i].second = i;
    }

    sort(minmoney.begin(), minmoney.end());
    sort(inv.begin(), inv.end());

    vector<int> solution(N);
    for (int i = 0; i < N; ++i) {
        if (minmoney[i].first > inv[i].first) {
            cout << "-1\n";
            return 0;
        }
        solution[minmoney[i].second] = inv[i].first;
    }

    for (int i = 0; i < N; ++i) {
        cout << solution[i];
        if (i != N - 1) cout << ' ';
    }
    cout << '\n';

    return 0;
}
