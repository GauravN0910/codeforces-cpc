#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
bool composites[MAX];
void sieve()
{
    composites[0] = composites[1] = true;
    for (int i = 4; i < MAX; i += 2)
    {
        composites[i] = true;
    }

    for (int i = 3; i * i <= MAX; i += 2)
    {
        if (!composites[i])
        {
            for (int j = i * i; j < MAX; j += 2 * i)
            {
                composites[j] = true;
            }
        }
    }
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        long long r = sqrt(n);
        if (r * r == n && !composites[r])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}