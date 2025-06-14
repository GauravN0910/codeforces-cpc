#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;

    string ans = "";
    int numZeros = n - k;
    for(int i=0;i<k;i++){
        ans += "1";
    }

    for(int i=0;i<numZeros;i++){
        ans += "0";
    }
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
