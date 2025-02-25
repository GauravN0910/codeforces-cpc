#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    int zeroCount = 0;
    int oneCount = 0;

    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            zeroCount++;
        }
        else{
            oneCount++;
        }
    }

    if(zeroCount==n){
        cout<<0<<endl;
        return;
    }
    if(oneCount==n){
        cout<<1<<endl;
        return;
    }

    int transitions = 0;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            transitions++;
        }
    }

    int ans = transitions + (s[0]=='1');
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