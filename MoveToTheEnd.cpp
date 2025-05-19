#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;

    vector<long long> nums(n);
    for(long long i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<long long> suffixSum(n);
    suffixSum[n-1] = nums[n-1];

    for(long long i=n-2; i>=0; i--){
        suffixSum[i] = nums[i] + suffixSum[i+1];
    }

    vector<long long> prefixBiggest(n);
    prefixBiggest[0] = nums[0];
    for(long long i=1; i<n; i++){
        prefixBiggest[i] = max(prefixBiggest[i-1], nums[i]);
    }

    vector<long long> suffixSmallest(n);
    suffixSmallest[n-1] = nums[n-1];
    for(long long i=n-2; i>=0; i--){
        suffixSmallest[i] = min(suffixSmallest[i+1], nums[i]);
    }

    for(long long i=n-1;i>=0; i--){
        if(i==0){
            cout<<suffixSum[i]<<" ";
            continue;
        }
        long long x = max(suffixSum[i], suffixSum[i] - nums[i] + prefixBiggest[i-1]);
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}