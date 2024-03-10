#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int prod = 1;

    for (int i = 1; i < n; i++)
    {
        if (__gcd(i, n) == 1)
        {
            prod *= i;
            prod %= n;
            ans++;
        }
    }
    if (prod != 1)
    {
        ans--;
    }
    cout << ans << endl;
}