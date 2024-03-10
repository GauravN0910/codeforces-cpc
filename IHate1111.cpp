#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<bool> check(1111, false);
    for (int i = 1; i < 1111; i++)
    {
        if (i % 11 == 0 || i % 111 == 0)
        {
            check[i] = true;
        }
        else if (i > 11 && check[i-11]){
            check[i] = true;
        }
        else if(i>111 && check[i-111]){
            check[i] = true;
        }
    }
    while (t--)
    {
        int n;
        cin >> n;

        if (n >= 1111)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (check[n])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}