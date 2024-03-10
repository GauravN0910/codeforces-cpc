#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long r, x, y, xx, yy;
    cin >> r >> x >> y >> xx >> yy;

    double dist = sqrt(pow(xx - x, 2) + pow(yy - y, 2));
    int ans = ceil(dist / (r * 2));
    cout << ans << endl;
}