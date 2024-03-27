#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> integers(n);
        vector<int> integerPerFriend(k);

        for (int i = 0; i < n; i++)
        {
            cin >> integers[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> integerPerFriend[i];
        }

        long long ans = 0;
        sort(integers.begin(), integers.end(), greater<int>());
        sort(integerPerFriend.begin(), integerPerFriend.end());

        int ind = k - 1;

        for (int i = 0; i < k; i++)
        {
            if (integerPerFriend[i] != 1)
            {
                ind = ind + integerPerFriend[i] - 1;
                ans += integers[i] + integers[ind];
            }
            else
            {
                ans += integers[i] * 2;
            }
        }
        cout << ans << endl;
    }
}