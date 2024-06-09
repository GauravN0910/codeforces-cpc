#include<bits/stdc++.h>
using namespace std;

int dp[20][2][4];

int solve(string& s, int idx, int tight, int count){
    if(idx==s.size()){
        return 1;
    }

    if(dp[idx][tight][count]!=-1){
        return dp[idx][tight][count];
    }

    int limit = (tight?s[idx] - '0':9);
    int ans = 0;
    for(int i=0;i<=limit;i++){
        int updateCount = count + (i!=0);
        if(updateCount<=3){
            ans += solve(s, idx+1, tight & (i==s[idx]-'0'), updateCount);
        }
    }
    return dp[idx][tight][count] = ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long l, r;
        cin>>l>>r;
        string sr = to_string(r);
        memset(dp, -1, sizeof(dp));
        long long ansr = solve(sr, 0, 1, 0);
        string sl = to_string(l-1);
        memset(dp, -1, sizeof(dp));
        long long ansl = solve(sl, 0, 1, 0);
        long long ans = ansr - ansl;
        cout<<ans<<endl;
    }
}