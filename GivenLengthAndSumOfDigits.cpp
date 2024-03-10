#include <bits/stdc++.h>
using namespace std;

int dp[101][901];

int main()
{
    int m, s;
    cin >> m >> s;

    string a, b;

    if (s == 0)
    {
        if (m == 1)
        {
            cout << "0 0" << endl;
        }
        else
        {
            cout << "-1 -1" << endl;
        }
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int x = min(s, 9);
        b += x + '0';
        s -= x;
    }

    if (s > 0)
    {
        cout << "-1 -1" << endl;
        return 0;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        a += b[i];
    }
    int i;
    for (i = 0; a[i] == '0'; i++)
        ;
    a[i]--;
    a[0]++;
    cout << a << " " << b << endl;
}