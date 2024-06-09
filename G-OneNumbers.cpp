#include<bits/stdc++.h>
using namespace std;

int dp[10][2][100];

bool isPrime(int n){
    if(n<=1){
        return false;
    }

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int dfs(string& s, int idx, int tight, int sum){
    if(idx==s.size()){
        if(isPrime(sum)){
            return 1;
        }
        return 0;
    }

    if(dp[idx][tight][sum]!=-1){
        return dp[idx][tight][sum];
    }

    int ans = 0;
    int limit = (tight?s[idx]-'0':9);
    for(int i=0;i<=limit;i++){
        int updateSum = sum + i;
        ans += dfs(s, idx+1, tight & (limit==i), updateSum);
    }
    return dp[idx][tight][sum] = ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long l, r;
        cin>>l>>r;
        string sl = to_string(l-1);
        string sr = to_string(r);
        memset(dp, -1, sizeof(dp));
        int ansr = dfs(sr, 0, 1, 0);
        memset(dp, -1, sizeof(dp));
        int ansl = dfs(sl, 0, 1, 0);
        int ans = ansr - ansl;
        cout<<ans<<endl;
    }
}