#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n);
        vector<long long> b(n);

        vector<long long> prev(n);
        vector<long long> ans;

        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (long long i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (long long i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                if (i < m)
                {
                    ans.push_back(a[i]);
                }
                prev[i] = min(a[i], b[i]);
            }
            else
            {
                if (i < m)
                {
                    ans.push_back(a[i] + prev[i + 1]);
                }
                prev[i] = prev[i + 1] + min(a[i], b[i]);
            }
        }

        cout << *min_element(ans.begin(), ans.end()) << endl;
    }
}