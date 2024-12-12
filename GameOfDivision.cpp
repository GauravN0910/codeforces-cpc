#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    for(int i=0;i<n;i++){
        int flag = true;
        for(int j=0;j<n;j++){
            if(i!=j){
                if((abs(nums[i]-nums[j]))%k==0){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}