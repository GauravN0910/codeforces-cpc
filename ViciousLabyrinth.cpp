#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> ans(n+1, 0);
    ans[n-1] = n;
    ans[n] = n-1;
    for(int i=1;i<n-1;i++){
        if(k%2){
            ans[i] = n;
        }
        else{
            ans[i] = n-1;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}