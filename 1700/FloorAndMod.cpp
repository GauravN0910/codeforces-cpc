#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long x, y;
    cin>>x>>y;
    long long ans = 0;

    for(long long k=1;k*k<=x;k++){
        ans += max(0LL, min(y, x/k - 1) - k);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}