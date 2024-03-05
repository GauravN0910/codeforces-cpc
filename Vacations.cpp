#include <bits/stdc++.h>
using namespace std;

int dp[105][3];

int dfs(vector<int> &nums, int n, int idx, int last)
{
    if (idx >= n)
    {
        return 0;
    }

    if (dp[idx][last] != -1)
    {
        return dp[idx][last];
    }

    int ans;
    if (nums[idx] == 0)
    {
        ans = 1 + dfs(nums, n, idx + 1, 0);
    }
    else if (nums[idx] == 1)
    {
        if (last == nums[idx])
        {
            ans = dfs(nums, n, idx + 1, 0) + 1;
        }
        else
        {
            ans = dfs(nums, n, idx + 1, 1);
        }
    }
    else if (nums[idx] == 2)
    {
        if (last == nums[idx])
        {
            ans = dfs(nums, n, idx + 1, 0) + 1;
        }
        else
        {
            ans = dfs(nums, n, idx + 1, 2);
        }
    }
    else
    {
        int contest = (last==1)?INT_MAX:dfs(nums, n, idx+1, 1);
        int gym =  (last==2)?INT_MAX:dfs(nums, n, idx+1, 2);
        ans = min(gym, contest);
    }
    return dp[idx][last] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    memset(dp, -1, sizeof(dp));

    int ans = dfs(nums, n, 0, 0);
    cout << ans;
}