#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums[x]++;
    }

    for(int i=1;i<n;i++){
        if(nums[i]==1){
            cout<<"NO"<<endl;
            return;
        }
        else if(nums[i]!=0){
            int count = nums[i];
            nums[i] = 2;
            nums[i+1] += count - 2;
        }
    }
    for(int i=1;i<=n;i++){
        if(nums[i]%2){
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