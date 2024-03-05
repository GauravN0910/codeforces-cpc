#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, time;
    cin >> n >> time;
    vector<int> book(n);
    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }
    int left = 0;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + book[i] <= time)
        {
            sum += book[i];
        }
        else
        {
            sum += book[i];
            while (sum > time)
            {
                sum -= book[left];
                left++;
            }
        }
        ans = max(ans, i-left+1);
    }
    cout<<ans<<endl;
}