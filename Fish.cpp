#include <bits/stdc++.h>
using namespace std;

double dp[(1 << 19)];
double probabilities[20][20];

double pMove(int prevMask, int j, int n)
{
    int alive = __builtin_popcount(prevMask);
    long long deno = (alive * (alive - 1) / 2);
    double moveProbability = 0;
    for (int fish = 0; fish < n; fish++)
    {
        if ((1 << fish) & prevMask)
        {
            moveProbability += probabilities[fish][j];
        }
    }
    return moveProbability / deno;
}

double solve(int mask, int n)
{
    int alive = __builtin_popcount(mask);
    if (alive == n)
    {
        return 1;
    }
    if (dp[mask] > -0.9)
    {
        return dp[mask];
    }

    double ans = 0;
    for (int fish = 0; fish < n; fish++)
    {
        if (!(mask & (1 << fish)))
        {
            int prevMask = mask ^ (1 << fish);
            double prevDay = solve(prevMask, n);
            ans += prevDay * pMove(prevMask, fish, n);
        }
    }
    return dp[mask] = ans;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> probabilities[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << solve(1 << i, n) << " ";
    }
    cout << endl;
}