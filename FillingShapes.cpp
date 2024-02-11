#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] = 2*dp[i-2];
    }
    cout<<dp[n]<<endl;
}

int main(){
    solve();
}