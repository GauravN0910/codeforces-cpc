#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    for(int i=0;i<n-1;i++){
        int x = min(nums[i], nums[i+1]);
        nums[i] -= x;
        nums[i+1] -= x;
    }

    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}