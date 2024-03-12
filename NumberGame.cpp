#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n==1){
        return false;
    }
    if(n==2){
        return true;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a = "Ashishgup";
        string b = "FastestFinger";

        if (n == 1)
        {
            cout << b << endl;
        }
        else if (n == 2 || n % 2)
        {
            cout << a << endl;
        }
        else
        {
            if ((n & (n - 1)) == 0)
            {
                cout << b << endl;
            }
            else if (n % 4 == 0)
            {
                cout << a << endl;
            }
            else if (isPrime(n / 2))
            {
                cout << b << endl;
            }
            else
            {
                cout << a << endl;
            }
        }
    }
}