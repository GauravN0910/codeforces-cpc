#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    long long n, k;
    cin>>n>>k;
    vector<long long> nums(n+1);
    for(long long i=1;i<=n;i++){
        cin>>nums[i];
    }

    long long ans = LLONG_MIN;
    for(long long i=n;i>=max(1LL, n-110);i--){
        for(long long j=i-1;j>=max(1LL, n-110);j--){
            ans = max(ans, i*j - k*(nums[i]|nums[j]));
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}