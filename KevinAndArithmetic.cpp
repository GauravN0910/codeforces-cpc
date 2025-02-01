#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int evenCount = 0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i]%2==0){
            evenCount += 1;
        }
    }
    
    int oddCount = n - evenCount;
    int ans = 0;
    if(evenCount){
        ans += 1;
    }
    if(ans){
        ans += oddCount;
    }
    else{
        ans += (oddCount - 1);
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