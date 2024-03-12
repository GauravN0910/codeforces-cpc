#include <bits/stdc++.h>
using namespace std;

/*
flip all the right side zeros and left side ones (or) flip all right side ones and left side zeros
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int zeroCount = 0;
        int oneCount = 0;
        for (auto c : s)
        {
            zeroCount += (c == '0');
            oneCount += (c == '1');
        }

        int ans = min(zeroCount, oneCount);
        int prefZero = 0;
        int prefOne = 0;
        for (auto c : s)
        {
            if (c == '0')
            {
                prefZero++;
                zeroCount--;
            }
            else
            {
                prefOne++;
                oneCount--;
            }
            ans = min({ans, prefOne + zeroCount, prefZero + oneCount});
        }
        cout << ans << endl;
    }
}