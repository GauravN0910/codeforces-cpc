#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int m, a, b, c;
    cin>>m>>a>>b>>c;

    int remainingSeats = 2*m;
    remainingSeats -= min(a, m);
    remainingSeats -= min(b, m);
    remainingSeats -= min(remainingSeats, c);

    int ans = (2*m) - remainingSeats;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}