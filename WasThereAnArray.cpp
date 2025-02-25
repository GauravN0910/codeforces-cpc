#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n-2);
    for(int i=0;i<n-2;i++){
        cin>>nums[i];
    }

    int sz = n-2;
    for(int i=0;i<sz;i++){
        if(nums[i]==0){
            if(i>0 && i<sz-1 && nums[i+1]==1 && nums[i-1]==1){
                cout<<"NO"<<endl;
                return;
            }
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