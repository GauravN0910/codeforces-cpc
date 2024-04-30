#include<bits/stdc++.h>
using namespace std;

int main(){
    int mod = 1e9+7;
    vector<int> dp(300000);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=300000;i++){
        dp[i] = (dp[i-1] + 2*(long long)(i-1)*dp[i-2])%mod;
    }
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        for(int i=0;i<k;i++){
            int a, b;
            cin>>a>>b;
            if(a!=b){
                n-=2;
            }
            else{
                n-=1;
            }
        }
        cout<<dp[n]<<endl;
    }
}