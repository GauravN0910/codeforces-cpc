#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int dp[505][505];

int dfs(int idx, vector<int>& speedLimit, vector<int>& signs, int k, int n){
    if(idx==n){
        return 0;
    }

    if(dp[idx][k]!=-1){
        return dp[idx][k];
    }

    int ans = 1e9;

    for(int j=idx+1;j<=n;j++){
        if(j-idx-1>k){
            break;
        }
        ans = min(ans, (signs[j] - signs[idx]) * speedLimit[idx] + dfs(j, speedLimit, signs, k - (j-idx-1), n));
    }


    return dp[idx][k] = ans;
}

void solve(){
    int n, l, k;
    cin>>n>>l>>k;

    vector<int> signs(n+1);
    vector<int> speedLimit(n+1);
    for(int i=0;i<n;i++){
        cin>>signs[i];
    }
    for(int i=0;i<n;i++){
        cin>>speedLimit[i];
    }
    signs[n] = l;

    memset(dp, -1, sizeof(dp));

    int ans = dfs(0, speedLimit, signs, k, n);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}