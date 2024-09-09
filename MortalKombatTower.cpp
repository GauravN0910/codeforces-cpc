#include<bits/stdc++.h>
using namespace std;

int dp[100005][2][2];
int dfs(vector<int>& nums, int idx, int player, int chance){
    if(idx==nums.size()){
        return 0;
    }

    if(dp[idx][player][chance]!=-1){
        return dp[idx][player][chance];
    }

    int samePlayer = 1e9;
    if(chance==0){
        samePlayer = dfs(nums, idx+1, player, chance+1) + (player==1 && nums[idx]==1);
    }

    int notSamePlayer = dfs(nums, idx+1, !player, 0) + (player==1 && nums[idx]==1);
    return dp[idx][player][chance] = min(samePlayer, notSamePlayer);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        memset(dp, -1, sizeof(dp));
        int ans = dfs(nums, 0, 1, 0);
        cout<<ans<<endl;
    }
}

