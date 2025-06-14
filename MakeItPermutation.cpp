#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;

    int ans = 2*(n-1) + 1;
    cout<<ans<<endl;
    for(int i=1;i<n;i++){
        cout<<i<<" "<<1<<" "<<i<<endl;
        cout<<i<<" "<<i+1<<" "<<n<<endl;
    }
    cout<<n<<" "<<1<<" "<<n<<endl;
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
