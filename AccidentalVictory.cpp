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
        vector<pair<long long, long long>> tokens;

        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            tokens.push_back({x, i});
        }

        sort(tokens.begin(), tokens.end());

        long long sum = 0;
        vector<long long> prefixSum;

        for (int i = 0; i < tokens.size(); i++)
        {
            sum = sum + tokens[i].first;
            prefixSum.push_back(sum);
        }

        vector<int> ans;

        long long last = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (prefixSum[i] >= last)
            {
                ans.push_back(tokens[i].second);
                last = tokens[i].first;
            }
        }
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for (int x : ans)
        {
            cout << x + 1 << " ";
        }
        cout << endl;
    }
}