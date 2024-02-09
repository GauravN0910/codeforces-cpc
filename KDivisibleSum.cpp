#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    if (n < k){
        int ans = k / n;
        if (k % n != 0)
        {
            ans++;
        }
        cout << ans << endl;
        return;
    }
    else if (n == k){
        cout << 1 << endl;
        return;
    }
    else{
        int x = n / k;
        if (n % k != 0)
        {
            x++;
        }
        k *= x;
        int ans = k / n;
        if (k % n != 0)
        {
            ans++;
        }
        cout << ans << endl;
        return;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}