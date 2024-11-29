#include<bits/stdc++.h>
using namespace std;

int dp[100005][6];

long long dfs(vector<long long>& scores, int idx, int k, int z){
    if(k==0 || idx<0 || idx>=scores.size()){
        return 0;
    }

    if(dp[idx][z]!=-1){
        return dp[idx][z];
    }

    long long ans = 0;
    if(idx<scores.size()){
        ans = max(ans, scores[idx] + dfs(scores, idx+1, k-1, z));
    }
    if(idx>=0 && z>0){
        ans = max(ans, scores[idx] + dfs(scores, idx-1, k-1, z-1));
    }
    return dp[idx][z] = ans;
}

void solve(){
    int n, k, z;
    cin>>n>>k>>z;
    vector<long long> scores(n);
    for(int i=0;i<n;i++){
        cin>>scores[i];
    }
    
    memset(dp, -1, sizeof(dp));
    long long ans = dfs(scores, 1, k, z) + scores[0];
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}