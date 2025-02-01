#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long dp[200005];

long long dfs(vector<long long>& nums, long long idx){
    if(idx==0){
        return nums[idx]==0;
    }

    if(idx==1){
        if(nums[idx]==1){
            return 1;
        }
        else if(nums[idx]==0){
            return nums[0]==0;
        }
        return 0;
    }

    if(dp[idx]!=-1){
        return dp[idx];
    }

    long long ans = 0;
    if(idx>=1 && nums[idx]==nums[idx-1]){
        ans += dfs(nums, idx-1);
    }
    if(idx>=2 && nums[idx]==nums[idx-2] + 1){
        ans += dfs(nums, idx-2);
    }

    return dp[idx] = (ans)%mod;
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }
    
    for(long long i=0;i<=n;i++){
        dp[i] = -1;
    }

    if(n==1){
        cout<<((nums[0]==0)?2:1)<<endl;
        return;
    }

    long long ans = dfs(nums, n-1) + dfs(nums, n-2);
    ans = (ans)%mod;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}