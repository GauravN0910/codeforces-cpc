#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> a;
    map<int, int> b;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b[x] = i;
    }

    map<int, int> c;

    for (int i = 1; i <= n; i++)
    {
        int moves = 0;
        if (a[i] >= b[i])
        {
            moves = a[i] - b[i];
        }
        else
        {
            moves = a[i] + n - b[i];
        }
        c[moves]++;
    }

    int ans = 0;
    for (auto elem : c)
    {
        ans = max(ans, elem.second);
    }
    cout << ans << endl;
}