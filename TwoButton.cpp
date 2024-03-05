#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, target;
    cin >> num >> target;
    int ans = 0;
    while (num != target)
    {
        ans++;
        if (target < num || target % 2 != 0)
        {
            target++;
        }
        else
        {
            target /= 2;
        }
    }
    cout << ans << endl;
}