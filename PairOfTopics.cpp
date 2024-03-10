#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] - b[i];
    }
    sort(c.begin(), c.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] > 0)
        {
            ans += (n - (i + 1));
        }

        else
        {
            int left = i + 1;
            int right = n - 1;
            long long x = -1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (c[i] + c[mid] > 0)
                {
                    x = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            if (x != -1)
            {
                ans += (n - x);
            }
        }
    }
    cout << ans << endl;
}