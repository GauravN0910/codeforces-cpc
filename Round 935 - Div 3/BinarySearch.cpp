#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int k = 0;
        vector<int> nums(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> nums[i];
            if (nums[i] == x)
            {
                k = i;
            }
        }

        int left = 1;
        int right = n + 1;
        while (left < right - 1)
        {
            long long mid = (left + right) / 2;
            if (nums[mid] > x)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        cout << 1 << endl;
        cout << left << " " << k << endl;
    }
}
