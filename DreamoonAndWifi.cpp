#include <bits/stdc++.h>
using namespace std;

double dfs(int finalDest, int currentPosition, string s2, int idx)
{
    if (idx == s2.size())
    {
        if (currentPosition == finalDest)
        {
            return 1;
        }
        return 0;
    }

    double ans = 0;
    if (s2[idx] != '?')
    {
        int change = (s2[idx] == '+') ? 1 : -1;
        ans = dfs(finalDest, currentPosition + change, s2, idx + 1);
    }
    else
    {
        ans += 0.5 * dfs(finalDest, currentPosition + 1, s2, idx + 1);
        ans += 0.5 * dfs(finalDest, currentPosition - 1, s2, idx + 1);
    }
    return ans;
}

int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;

    int finalDest = 0;
    for (auto x : s1)
    {
        if (x == '+')
        {
            finalDest++;
        }
        else
        {
            finalDest--;
        }
    }

    double ans = dfs(finalDest, 0, s2, 0);
    cout << setprecision(9) << ans << endl;
}