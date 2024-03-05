#include <bits/stdc++.h>
using namespace std;

int dfs(int n, int a, int b, int c, vector<int> &dp)
{
    if (n < 0)
    {
        return -1000000;
    }
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = 1 + max({dfs(n - a, a, b, c, dp), dfs(n - b, a, b, c, dp), dfs(n - c, a, b, c, dp)});
    return dp[n] = ans;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 1, -1);
    int ans = dfs(n, a, b, c, dp);
    cout << ans << endl;
}