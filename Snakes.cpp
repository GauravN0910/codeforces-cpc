#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, q;

int getMinGap(int i, int j, vector<pair<int, int>>& operations){
    int gap = 1;
    int l1 = 1, r1 = 1;
    int l2 = 2, r2 = 2;
    for(auto [snake, type]:operations){
        if(snake==j){
            if(type==1){
                r2++;
            }
            else{
                l2++;
            }
        }
        if(snake==i){
            if(type==-1){
                l1++;
            }
            else{
                if(r1+1==l2){
                    l2++;
                    r2++;
                    gap++;
                }
                r1++;
            }
        }
    }
    return gap;
}

int dfs(vector<vector<int>>& minGap, vector<vector<int>>& dp, vector<int>& maxIncrease, int node, int mask){
    if(mask == (1<<n)-1){
        return maxIncrease[node] + 1;
    }

    if(dp[mask][node]!=-1){
        return dp[mask][node];
    }

    int ans = 1e9;
    for(int i=0;i<n;i++){
        if((mask & (1<<i)) == 0){
            ans = min(ans, minGap[node][i] + dfs(minGap, dp, maxIncrease, i, mask ^ (1<<i)));
        }
    }
    return dp[mask][node] = ans;
}

void solve(){
    cin>>n>>q;

    vector<pair<int, int>> operations(q);
    vector<int> maxIncrease(n);
    for(int i=0;i<q;i++){
        int x; cin>>x;
        x--;
        char op; cin>>op;
        if(op=='+'){
            operations[i] = {x, 1};
            maxIncrease[x]++;
        }
        else{
            operations[i] = {x, -1};
        }
    }

    vector<vector<int>> minGap(n+1, vector<int>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                minGap[i][j] = getMinGap(i, j, operations);
            }
        }
    }

    vector<vector<int>> dp((1<<(n)), vector<int>(n, -1));

    int ans = 1e9;
    for(int i=0;i<n;i++){
        ans = min(ans, dfs(minGap, dp, maxIncrease, i, (1<<i)));
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}