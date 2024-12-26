#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long k, l1, r1, l2, r2;
    cin>>k>>l1>>r1>>l2>>r2;

    long long ans = 0;
    
    long long kPowerN = 1;
    while(kPowerN<=1e9){
        long long quoL = l2/kPowerN;
        if(l2%kPowerN){
            quoL++;
        }
        long long quoR = r2/kPowerN;
        long long limitL = max(l1, quoL);
        long long limitR = min(r1, quoR);

        long long count = limitR - limitL + 1;
        if(limitR>=limitL){
            ans += count;
        }
        kPowerN *= k;
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