#include <bits/stdc++.h>
using namespace std;

int dp[1001][(1 << 11)];
int mod = 1e9 + 7;

void generateMasks(int mask, int row, int nextMask, int n, vector<int> &nextMasks)
{
    if (row == n + 1)
    {
        nextMasks.push_back(nextMask);
        return;
    }

    if ((mask & (1 << row)) != 0)
    {
        generateMasks(mask, row + 1, nextMask, n, nextMasks);
    }

    if (row != n)
    {
        if ((mask & (1 << row)) == 0 && (mask & (1 << (row + 1))) == 0)
        {
            generateMasks(mask, row + 2, nextMask, n, nextMasks);
        }
    }

    if ((mask & (1 << row)) == 0)
    {
        generateMasks(mask, row + 1, nextMask ^ (1 << row), n, nextMasks);
    }
}

int solve(int col, int mask, const int m, const int n)
{
    if (col == m + 1)
    {
        if (mask == 0)
        {
            return 1;
        }
        return 0;
    }

    if (dp[col][mask] != -1)
    {
        return dp[col][mask];
    }

    int ans = 0;
    vector<int> nextMasks;
    generateMasks(mask, 1, 0, n, nextMasks);

    for (int nextMask : nextMasks)
    {
        ans = (ans + solve(col + 1, nextMask, m, n)) % mod;
    }
    return dp[col][mask] = ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    int ans = solve(1, 0, m, n);
    cout << ans << endl;
}