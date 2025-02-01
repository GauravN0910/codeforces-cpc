#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;

    vector<int> ans(n);
    ans[0] = 1;
    ans[1] = 1;
    ans[n-1] = 1;

    int val = 2;
    for(int i=2;i<=n-2;i++){
        ans[i] = val++;
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}