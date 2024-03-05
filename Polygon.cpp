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
        string poly[n];
        for (int i = 0; i < n; i++)
        {
            cin >> poly[i];
        }

        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (poly[i][j] == '1' && poly[i][j + 1] == '0' && poly[i + 1][j] == '0')
                {
                    flag = false;
                    break;
                }
                if (!flag)
                {
                    break;
                }
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}