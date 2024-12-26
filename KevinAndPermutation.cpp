#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> ans(n+1, -1);
    int num = 1;
    for(int i=k;i<=n;i+=k){
        ans[i] = num;
        num++;
    }

    for(int i=1;i<=n;i++){
        if(ans[i]==-1){
            ans[i] = num;
            num++;
        }
    }
    for(int i=1;i<=n;i++){
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