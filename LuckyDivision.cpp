#include <bits/stdc++.h>
using namespace std;

void findLucky(int n, vector<int> &lucky)
{
    for (int i = 4; i <= n; i++)
    {
        string s = to_string(i);
        bool flag = true;
        for (auto c : s)
        {
            if (c != '4' && c != '7')
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            lucky.push_back(i);
        }
    }
}

bool solve(int n, vector<int> &lucky)
{
    for (auto num : lucky)
    {
        if (n % num == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> lucky;
    findLucky(n, lucky);
    bool x = solve(n, lucky);
    if (x)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}