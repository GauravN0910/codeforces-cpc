#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    string ans = "";
    if(n==1){
        cout<<"x"<<endl;
        return;
    }
    
    if(n%2){
        for(int i=0;i<n/2;i++){
            ans += "x";
        }
        ans += "y";
        ans += "z";
        int remaining = n - (n/2) - 2;
        for(int i=0;i<remaining;i++){
            ans += "x";
        }
    }
    else{
        for(int i=0;i<n/2;i++){
            ans += "x";
        }
        ans += "y";
        int remaining = n - (n/2) - 1;
        for(int i=0;i<remaining;i++){
            ans += "x";
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