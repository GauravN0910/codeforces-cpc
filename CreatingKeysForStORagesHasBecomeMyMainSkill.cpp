#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> ans(n, x);
    for(int i=0;i<n;i++){
        if((i & x) == i){
            ans[i] = i;
        }
    }

    int bitwiseOR = 0;
    for(int i=0;i<n;i++){
        bitwiseOR |= ans[i];
    }
    if(bitwiseOR!=x){
        ans[n-1] = x;
    }
    for(int i=0;i<n;i++){
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