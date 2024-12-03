#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, k;
    cin>>n>>m>>k;

    string s;
    cin>>s;
    int ans = 0;
    int idx = 0;
    while(idx<n){
        if(s[idx]=='0'){
            int count = 0;
            while(s[idx]=='0' && count<m){
                idx++;
                count++;
            }
            if(count==m){
                ans++;
                idx += (k-1);
            }
        }
        else{
            idx++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}