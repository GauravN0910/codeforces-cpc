#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int dp[505][505];

int dfs(string& s, int l, int r){
    if(l>r){
        return 0;
    }

    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    int ans = 1 + dfs(s, l+1, r);
    for(int i=l+1;i<=r;i++){
        if(s[i]==s[l]){
            ans = min(ans, dfs(s, l+1, i-1) + dfs(s, i, r));
        }
    }
    return dp[l][r] = ans;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    memset(dp, -1, sizeof(dp));
    int ans = dfs(s, 0, n-1);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t = 1;
    while(t--){
        solve();
    }
}