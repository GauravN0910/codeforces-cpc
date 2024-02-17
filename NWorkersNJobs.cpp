#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &costs, int n, int i, int mask, vector<vector<int>> &dp)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[i][mask] != -1)
    {
        return dp[i][mask];
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))
        {
            ans = min (ans, costs[j][i] + dfs(costs, n, i + 1, (mask ^ (1 << j)), dp));
        }
    }
    return dp[i][mask] = ans;
}

int solve(vector<vector<int>> &costs, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>((1 << (n + 1)), -1));
    return dfs(costs, n, 0, (1 << n) - 1, dp);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> costs(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> costs[i][j];
        }
    }

    int ans = solve(costs, n);
    cout << ans << endl;
}