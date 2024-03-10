#include <bits/stdc++.h>
using namespace std;

long long dp[2][100001];

long long dfs(vector<vector<long long>> &heights, int row, int idx)
{
    if (idx == heights[0].size())
    {
        return 0;
    }
    if (dp[row][idx] != -1)
    {
        return dp[row][idx];
    }
    long long pick = heights[row][idx] + dfs(heights, (row + 1) % 2, idx + 1);
    long long notPick = dfs(heights, row, idx+1);
    long long ans = max(pick, notPick);
    return dp[row][idx] = ans;
}   

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> heights(2, vector<long long>(n));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> heights[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for (int i = 0; i < 2; i++)
    {
        ans = max(ans, dfs(heights, i, 0));
    }
    cout << ans << endl;
}