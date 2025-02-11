#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long dp[2005][2005];

long long dfs(long long left, long long right, vector<long long>& nums){
    if(left==right){
        return 0;
    }
    if(dp[left][right]!=-1){
        return dp[left][right];
    }
    long long ans = nums[right] - nums[left] + min(dfs(left+1, right, nums), dfs(left, right-1, nums));
    return dp[left][right] = ans;
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());

    memset(dp, -1, sizeof(dp));
    long long ans = dfs(0, n-1, nums);
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