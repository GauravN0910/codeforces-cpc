#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int dp[101][2];

int dfs(int n, int k, int d, int sum, int taken){
    if(sum==n){
        if(taken){
            return 1;
        }
        return 0;
    }
    
    if(dp[sum][taken]!=-1){
        return dp[sum][taken];
    }

    int ans = 0;
    for(int x=1;x<=k;x++){
        if(sum+x<=n){
            ans = (ans + dfs(n, k, d, sum+x, taken | (x>=d)))%mod;
        }
    }
    return dp[sum][taken] = ans%mod;
}

int main(){
    int n, k, d;
    cin>>n>>k>>d;
    memset(dp, -1, sizeof(dp));
    int ans = dfs(n, k, d, 0, 0);
    cout<<ans<<endl;
}