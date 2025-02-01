#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string s;
    cin>>s;
    int oneCount = 0;
    for(auto ch:s){
        if(ch=='1'){
            oneCount++;
        }
    }

    cout<<oneCount<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}