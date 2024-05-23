#include<bits/stdc++.h>
using namespace std;
 
int mod = 1e9+7;
int dp[100005];
 
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='m' || s[i]=='w'){
            cout<<"0"<<endl;
            return 0;
        }
    }
 
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1];
        if(s.substr(i-2, 2)=="nn" || s.substr(i-2, 2)=="uu"){
            dp[i] = (dp[i] + dp[i-2])%mod;
        }
    }
    ans = dp[n];
    cout<<ans<<endl;
}
