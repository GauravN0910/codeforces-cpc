#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cout<<(i==0?i:i^i-1)<<endl;
        int x;
        cin>>x;
        if(x==1){
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}