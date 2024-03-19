#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<long long, long long> map;
        long long maxCount = 0;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            map[x]++;
            maxCount = max(maxCount, map[x]);
        }

        long long ans = 0;
        if (2 * maxCount > n)
        {
            ans = (2 * maxCount - n);
        }
        else if (n % 2)
        {
            ans = 1;
        }

        cout << ans << endl;
    }
}