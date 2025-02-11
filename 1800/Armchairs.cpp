#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;



long long dfs(long long i, long long j, vector<long long>& nums, vector<long long>& occupied, vector<vector<long long>>& dp){
    if(j==occupied.size()){
        return 0;
    }
    if(i==nums.size()){
        return 1e18;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    long long take = 1e18;
    if(nums[i]==0){
        take = abs(i-occupied[j]) + dfs(i+1, j+1, nums, occupied, dp);
    }
    long long notTake = dfs(i+1, j, nums, occupied, dp);
    return dp[i][j] = min(take, notTake);
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<long long> occupied;
    for(long long i=0;i<n;i++){
        if(nums[i]==1){
            occupied.push_back(i);
        }
    }
    int k = occupied.size();
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, -1));
    long long ans = dfs(0, 0, nums, occupied, dp);
    cout<<ans<<endl;
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