#include <bits/stdc++.h>
using namespace std;

int grundy[2001];
void precompute()
{
    for (int i = 3; i <= 2000; i++)
    {
        set<int> mex;
        for (int j = 1; j <= i; j++)
        {
            int k = i - j;
            if (k > 0 && j > 0 && k != j)
            {
                mex.insert(grundy[k]^grundy[j]);
            }
        }

        int res_mex = 0;
        for(int x:mex){
            if(x==res_mex){
                res_mex++;
            }
            else{
                break;
            }
        }
        grundy[i] = res_mex;
    }
}

int main()
{
    int t;
    cin >> t;
    precompute();
    while (t--)
    {
        int n;
        cin >> n;
        n = min(2000, n);
        if (grundy[n] == 0)
        {
            cout << "second" << endl;
        }
        else
        {
            cout << "first" << endl;
        }
    }
}