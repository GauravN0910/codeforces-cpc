#include<bits/stdc++.h>
using namespace std;

int cost[100001];
long long dp[100001][2];
string strings[100001][2];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }

    for(int i=1;i<=n;i++){
        cin>>strings[i][0];
        strings[i][1] = strings[i][0];
        reverse(strings[i][1].begin(), strings[i][1].end());

        for(int j=0;j<2;j++){
            dp[i][j] = 1e18;
            for(int k=0;k<2;k++){
                if(strings[i][j] >= strings[i-1][k]){
                    dp[i][j] = min(dp[i][j], cost[i]*j + dp[i-1][k]);
                }
            }
        }
    }

    long long ans = min(dp[n][0], dp[n][1]);
    cout<<(ans>=1e18?-1:ans)<<endl;
}