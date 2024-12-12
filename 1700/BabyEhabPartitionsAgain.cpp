#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;


void solve(){
    int n;
    cin>>n;

    vector<int> nums(n);
    int sum = 0;

    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum += nums[i];
    }

    if(sum%2){
        cout<<0<<endl;
        return;
    }

    int target = sum/2;

    vector<vector<bool>> dp(n+1,vector<bool>(target+1));

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=target; j++) {
            if(i==0)    
                dp[i][j]=false;
            else if(j==0)
                dp[i][j]=true;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            
            dp[i][j] = dp[i-1][j];
            if(nums[i-1]<=j){
                dp[i][j] = (dp[i-1][j-nums[i-1]] || dp[i][j]);
            }

        }
    }

    if(!dp[n][target]){
        cout<<0<<endl;
        return;
    }
    else{
        while(true){
            for(int i=0;i<n;i++){
                if(nums[i]%2){
                    cout<<1<<endl;
                    cout<<i+1<<endl;
                    return;
                }
                else{
                    nums[i]/=2;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}