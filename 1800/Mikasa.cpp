#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;
    
    int ans = 0;
    if(n>=m+1){
        cout<<0<<endl;
        return;
    }
    int x = m+1;
    for(int bit=30;bit>=0;bit--){
        if((n>>bit & 1) == (x>>bit & 1)){
            continue;
        }
        if((n>>bit & 1)){
            break;
        }
        else{
            ans |= 1<<bit;
        }

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