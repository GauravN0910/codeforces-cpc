#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, k;
    cin>>n>>k;

    vector<long long> dp(k+1, 0);
    dp[0] = 1;

    for(long long i=1;i<=n;i++){
        vector<long long> newDP(k+1, 0);
        for(long long j=0;j<=k;j++){
            newDP[j] = (dp[j] + newDP[j])%mod;
            if(j>0){
                newDP[j] = (newDP[j] + newDP[j-1])%mod;
            }
            if(j-i>=0){
                newDP[j] = (newDP[j] - dp[j-i] + mod)%mod;
            }
        }
        dp = newDP;
    }
    cout<<dp[k]<<endl;
}

int main(){   
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t = 1;
    while(t--){
        solve();
    }
}