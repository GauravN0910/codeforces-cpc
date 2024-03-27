#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k, i;
    cin >> n >> k;
    set<long long> factors;
    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.insert({i, n / i});
        }
    }

    if (k <= factors.size())
    {
        cout << *next(factors.begin(), k - 1);
    }
    else
    {
        cout << -1;
    }
    return 0;
}