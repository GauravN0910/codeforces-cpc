#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long dfs(long long idx, long long time, vector<vector<long long>>& dp, vector<long long>& nums){
    if(idx==nums.size()){
        return 0;
    }

    if(dp[idx][time]!=-1){
        return dp[idx][time];
    }

    long long operationNow = INT_MAX;
    long long operationLater = INT_MAX;
    if(time>=nums[idx]){
        operationNow = abs(time - nums[idx]) + dfs(idx + 1, time + 1, dp, nums);
    }
    else{
        operationNow = abs(time - nums[idx]) + dfs(idx + 1, time + 1, dp, nums);
        operationLater = dfs(idx, time + 1, dp, nums);
    }
    return dp[idx][time] = min(operationNow, operationLater);
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<vector<long long>> dp(n + 5, vector<long long>(2*n + 5, -1));
    long long ans = dfs(0, 1, dp, nums);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}