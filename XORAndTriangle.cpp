#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    if((__builtin_popcount(n)==1) || __builtin_popcount(n+1)==1){
        cout<<-1<<endl;
        return;
    }

    int ans = 1;
    while(ans*2<=n){
        ans *= 2;
    }
    cout<<ans-1<<endl;
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