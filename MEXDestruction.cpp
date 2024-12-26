#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int sum = 0;
    vector<int> zeroIdx;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum += nums[i];
        
    }

    if(sum==0){
        cout<<0<<endl;
        return;
    }
    
    int idx = 0;
    bool flag = false;
    while(idx<n){
        if(nums[idx]){
            if(!flag){
                while(idx<n && nums[idx]){
                    idx++;
                }
                flag = true;
            }
            else{
                cout<<2<<endl;
                return;
            }
        }
        idx++;
    }

    cout<<1<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}