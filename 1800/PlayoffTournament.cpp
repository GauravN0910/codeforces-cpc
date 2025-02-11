#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int k;
    cin >> k;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s = 'x' + s;

    int n = 1 << k;
    vector<int> dp(2*n, 1);

    auto dfs = [&](int idx) {
        return dp[idx] = (s[idx]!='0'? dp[idx * 2] : 0) + (s[idx]!='1'? dp[idx*2 + 1] : 0);
    };

    for (int i=n-1;i>=1;i--) {
        dfs(i);
    }

    int q;
    cin >> q;
    while (q--) {
        int idx;
        char x;
        cin >> idx >> x;
        idx = n - idx;
        s[idx] = x;
        while (idx) {
            dfs(idx);
            idx = idx/2;
        }
        cout<<dp[1]<<endl;
    }
}