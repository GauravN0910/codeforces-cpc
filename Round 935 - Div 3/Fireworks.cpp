#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, m;
        cin >> a >> b >> m;
        long long ans = 0;
        ans += m / a;
        ans += m / b;
        ans += 2;

        cout << ans << endl;
    }
}