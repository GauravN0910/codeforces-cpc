#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    long long n, k;
    cin>>n>>k;
    vector<long long> ans(n);

    for(int i=0;i<n;i++){
        if(((n-1)&i)==i){
            ans[i] = k;
        }
        else{
            ans[i] = 0;
        }
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

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}