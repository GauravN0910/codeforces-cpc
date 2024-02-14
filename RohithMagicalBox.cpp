#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        string ans = "";
        vector<char> valid = {'0', '1', '2', '3', '4', '6', '7', '8', '9'};

        while (n)
        {
            int d = n % 9;
            n /= 9;
            ans += valid[d];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}