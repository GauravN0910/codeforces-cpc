#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long twoPowerN;
long long pickEven;

long long factorial[200005];
long long invFactorial[200005];

long long n, k;

long long binExp(long long n, long long pow){
    if(pow==0){
        return 1;
    }
    long long ans = binExp(n, pow/2);
    if(pow%2){
        return ((ans*ans)%mod * n)%mod;
    }
    return (ans*ans)%mod;
}

long long invMod(long long n){
    return (binExp(n, mod-2))%mod;
}

void calculateFactorial(){
    factorial[0] = 1;
    invFactorial[0] = 1;
    for(long long i=1;i<200005;i++){
        factorial[i] = (factorial[i-1] * i)%mod;
        invFactorial[i] = invMod(factorial[i])%mod;
    }
}

long long combination(long long n, long long r){
    return ((factorial[n] * invFactorial[n-r])%mod * invFactorial[r])%mod;
}

long long dfs(long long i, long long equal, vector<vector<long long>>& dp){
    if(i<0){
        return 1;
    }

    if(dp[i][equal]!=-1){
        return dp[i][equal];
    }

    if(equal==0){
        return dp[i][equal] = (twoPowerN * dfs(i-1, equal, dp))%mod;
    }

    if(n%2){
        return dp[i][equal] = (dfs(i-1, 1, dp) * (pickEven + 1) % mod) % mod; 
    }
    else{
        return dp[i][equal] = ((dfs(i-1, 1, dp) * pickEven)%mod + dfs(i-1, 0, dp))%mod;
    }

}

void solve(){
    cin>>n>>k;
    twoPowerN = 1;
    for(long long i=0;i<n;i++){
        twoPowerN = (twoPowerN * 2)%mod;
    }

    pickEven = 0;
    for(long long i=0;i<n;i+=2){
        pickEven = (pickEven + combination(n, i))%mod;
    }
    vector<vector<long long>> dp(k, vector<long long>(2, -1));

    long long ans = dfs(k-1, 1, dp);
    cout<<ans<<endl;
}

int main(){
    calculateFactorial();
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}