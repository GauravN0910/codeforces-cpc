#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
bool people[11][101];
void in(int n)
{
    string s;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        stringstream in(s);
        int a;
        while(in>>a)
        {
            people[i][a] = 1;
        }
    }
}

long long dp[101][1025];
long long solve(int shirt, int mask, int n)
{

    if(mask == ((1<<n)-1))
        return 1;

    if(shirt > 100)
        return 0;

    if(dp[shirt][mask] != -1)
        return dp[shirt][mask];
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        if((mask & (1<<(i))) != 0)
            continue;
        if(people[i][shirt])
        {
            int temp_msk = (mask|(1<<(i)));
            ans = (ans + solve(shirt+1, temp_msk, n))%mod;
        }
    }

    ans = (ans + solve(shirt+1, mask, n))%mod;

    return dp[shirt][mask] = ans;
}

int main(){
    int n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(people, 0, sizeof people);
        memset(dp, -1, sizeof dp);
        in(n);
        cout<<solve(1,0,n)<<endl;
    }
    return 0;
}