#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<long long> prefixSum(n+1, 0);
    vector<long long> suffixSum(n+1, 0);

    for(long long i=0;i<n;i++){
        prefixSum[i+1] = prefixSum[i] + max(nums[i], 0LL);
    }

    for(long long i=n-1;i>=0;i--){
        suffixSum[i] = suffixSum[i+1] + max(-1*nums[i], 0LL);
    }

    long long ans = 0;
    for(long long i=0;i<=n;i++){
        ans = max(ans, prefixSum[i] + suffixSum[i]);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}