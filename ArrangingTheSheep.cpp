#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        long long sheep = 0;
        long long empty = 0;

        vector<long long> position(n);
        for (long long i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                position[sheep] = i;
                sheep++;
            }
        }

        long long center = sheep / 2;
        long long ans = 0;
        for (long long i = 0; i < sheep; i++)
        {
            if (i == center)
            {
                continue;
            }
            else
            {
                ans += (abs(position[center] - position[i]) - abs(center - i));
            }
        }
        cout << ans << endl;
    }
}