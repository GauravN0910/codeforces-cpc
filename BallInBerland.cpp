#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;

        vector<int> boyCouple(k, 0);
        vector<int> girlCouple(k, 0);
        vector<int> boy(a + 1, 0);
        vector<int> girl(b + 1, 0);

        for (int i = 0; i < k; i++)
        {
            cin >> boyCouple[i];
            boy[boyCouple[i]]++;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> girlCouple[i];
            girl[girlCouple[i]]++;
        }

        long long ans = 0;

        for (int i = 0; i < k; i++)
        {
            ans += k - boy[boyCouple[i]] - girl[girlCouple[i]] + 1;
        }
        cout << ans / 2 << endl;
    }
}