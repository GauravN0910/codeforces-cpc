#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        vector<long long int> nums(n), dp(n);

        for (int i = 0; i < n; i++)
            dp[i] = 1;

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        for (int i = 0; i < n; i++)
        {

            long long int keep = i + 1;

            for (int j = keep * 2; j <= n; j += keep)
            {

                if (nums[j - 1] > nums[i])
                {

                    dp[j - 1] = max(dp[j - 1], dp[i] + 1);
                }
            }
        }
        long long ans = *max_element(dp.begin(), dp.end());
        cout<<ans<<endl;
    }
}