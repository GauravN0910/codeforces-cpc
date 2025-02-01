#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int l, r;
    cin>>l>>r;
    if(l==1 && r==1){
        cout<<1<<endl;
        return;
    }
    cout<<r-l<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}