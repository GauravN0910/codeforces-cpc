#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    string ans = "";
    for(int i=0;i<n-2;i++){
        ans += s[i];
    }
    ans += "i";
    cout<<ans<<endl;
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