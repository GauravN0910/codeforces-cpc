#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, x, y;
    cin>>n>>x>>y;

    if(x>y){
        cout<<0<<endl;
        return;
    }

    vector<long long> nums(n);
    long long sum = 0;
    for(long long i=0;i<n;i++){
        cin>>nums[i];
        sum += nums[i];
    }

    sort(nums.begin(), nums.end());

    long long upperLimit = sum - x;
    long long lowerLimit = sum - y;

    long long ans = 0;

    for(long long i=0;i<n;i++){
        long long diffLower = lowerLimit - nums[i];
        long long diffUpper = upperLimit - nums[i];

        long long left = lower_bound(nums.begin() + i + 1, nums.end(), diffLower) - nums.begin();
        long long right = upper_bound(nums.begin() + i + 1, nums.end(), diffUpper) - nums.begin() - 1;

        if(right >= left){
            ans += right - left + 1;
        }
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