#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;

        ans += a;

        int r = b % 3;
        int q = b / 3;
        ans += q;

        if (r == 0)
        {
            ans += ceil(1.0 * c / 3);
        }

        else if (r == 1)
        {
            if(c<2){
                ans = -1;
            }
            else{
                c-=2;
                ans += ceil(1.0 * c / 3);
                ans += 1;
            }
        }

        else if(r==2){
            if(c<1){
                ans = -1;
            }

            else {
                c-=1;
                ans += ceil(1.0 * c / 3);
                ans +=1;
            }
        }

        cout << ans << endl;
    }
}