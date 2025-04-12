#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, x;
    cin>>n>>x;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    long long ans = 0;
    long long prevIdx = 0;
    for(long long i=0;i<n;i++){
        if(nums[i] * (i - prevIdx + 1) >= x){
            ans++;
            prevIdx = i + 1;
        }
    }

    cout<<ans<<endl;
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