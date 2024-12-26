#include <bits/stdc++.h>
using namespace std;

int mexVal(set<int>& s) {
    int mex = 0;
    while (s.find(mex) != s.end()) {
        mex++;
    }
    return mex;
}

void solve() {
    int n, x, y;
    cin>>n>>x>>y;

    vector<int> ans(n, -1);
    vector<set<int>> graph(n);

    for (int i = 0; i < n; ++i) {
        graph[i].insert((i + 1) % n);
        graph[i].insert((i - 1 + n) % n);
    }

    x--; y--;
    graph[x].insert(y);
    graph[y].insert(x);

    for (int node = 0; node < n; node++) {
        set<int> mutualFriends;
        for (int neighbor : graph[node]) {
            if (ans[neighbor] != -1) {
                mutualFriends.insert(ans[neighbor]);
            }
        }
        ans[node] = mexVal(mutualFriends);
    }

    for(auto val:ans){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

