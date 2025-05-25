#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }

    vector<int> low(n+1);
    vector<int> high(n+1);
    for(int i=1;i<=n;i++){
        cin>>low[i]>>high[i];
    }

    vector<vector<int>> states(n+1, vector<int>(2, 0));
    for(int i=1;i<=n;i++){
        int lower = 0;
        int higher = 0;
        if(nums[i]==0){
            lower = states[i-1][0];
            higher = states[i-1][1];
        }
        else if(nums[i]==1){
            lower = states[i-1][0] + 1;
            higher = states[i-1][1] + 1;
        }
        else{
            lower = states[i-1][0];
            higher = states[i-1][1] + 1;
        }

        int lowLimit = max(lower, low[i]);
        int highLimit = min(higher, high[i]);
        if(lowLimit > highLimit){
            cout<<-1<<endl;
            return;
        }
        states[i][0] = lowLimit;
        states[i][1] = highLimit;
    }

    int curHeight = states[n][0];
    vector<int> ans;

    for(int i=n;i>=1;i--){
        if(nums[i]!=-1){
            ans.push_back(nums[i]);
            curHeight -= nums[i];
        }
        else{
            if(curHeight >= states[i-1][0] && curHeight <= states[i-1][1]){
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
                curHeight -= 1;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}