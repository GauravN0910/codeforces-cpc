#include <bits/stdc++.h>
using namespace std;

int n, l, r, x;
int nums[20];

int dfs(int sum, int minElem, int maxElem, int idx)
{
    if (idx == n)
    {
        return (sum >= l && sum <= r && maxElem - minElem >= x);
    }

    int pick = dfs(sum + nums[idx], min(minElem, nums[idx]), max(maxElem, nums[idx]), idx + 1);
    int notPick = dfs(sum, minElem, maxElem, idx + 1);
    return pick + notPick;
}

int main()
{
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = dfs(0, 1e9, 0, 0);
    cout << ans << endl;
}