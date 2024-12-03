#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    int sum = 0;
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        sum += nums[i];
        if(sum>k){
            break;
        }
        else{
            ans = min(ans, k-sum);
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}