#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    long long sum = 0;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
        sum += nums[i];
    }


    vector<long long> prefixSum(n);
    
    prefixSum[0] = nums[0];

    for(long long i=1;i<n;i++){
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }

    long long ans = 0;
    long long count = 0;
    for(long long i=0;i<n-1;i++){
        if(prefixSum[i]*3 == prefixSum[n-1]*2){
            ans += count;
        }
        if(prefixSum[i]*3 == prefixSum[n-1]){
            count++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t = 1;
    while(t--){
        solve();
    }
}