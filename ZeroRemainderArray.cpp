#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        map<long long, long long> modMap;
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            if ((y % k))
            {
                modMap[k - (y % k)]++;
            }
        }

        long long ans = 0;

        for (auto elem : modMap)
        {
            ans = max(ans, (k * (elem.second - 1)) + elem.first + 1);
        }
        cout << ans << endl;
    }
}