#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int dp[1005][1005];

int dfs(string& a, string& b, string& c, int i, int j){
    if(i==a.size() && j==b.size()){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int takeA = 1e9;
    int takeB = 1e9;

    if(i!=a.size()){
        takeA = !(a[i]==c[i+j]) + dfs(a, b, c, i+1, j);
    }
    if(j!=b.size()){
        takeB = !(b[j]==c[i+j]) + dfs(a, b, c, i, j+1);
    }
    return dp[i][j] = min(takeA, takeB);
}

void solve(){
    string a, b, c;
    cin>>a>>b>>c;

    int n = a.size();
    int m = b.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = -1;
        }
    }


    int ans = dfs(a, b, c, 0, 0);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}