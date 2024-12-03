#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a, b;
    cin>>a>>b;
    int ans;
    for(int i=a;i<=1e6;i++){
        if(i%a == i%b){
            ans=i;
            break;
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