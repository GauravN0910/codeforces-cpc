#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        events.push_back({arr[i] - k, 1});
        events.push_back({arr[i] + k + 1, -1});
    }

    sort(events.begin(), events.end());

    int res = 0;
    int cnt = 0;

    for (const auto& event : events) {
        cnt += event.second;
        res = max(res, cnt);
    }

    cout << res << endl;
    return 0;
}
