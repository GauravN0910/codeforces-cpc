#include <bits/stdc++.h>
using namespace std;

bool isValid(int mid, unordered_map<int, int> &map, int k)
{
    int total = 0;
    for (auto elem : map)
    {
        total += min(elem.second, mid);
    }
    return total >= k * mid;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        unordered_map<int, int> map;
        for (int num : nums)
        {
            map[num]++;
        }

        int left = 0;
        int right = n;
        int ans = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (isValid(mid, map, k))
            {
                ans = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        cout << ans << endl;
    }
}
