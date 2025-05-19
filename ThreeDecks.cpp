#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int a, b, c;
    cin>>a>>b>>c;

    int sum = a + b + c;
    if(sum%3){
        cout<<"NO"<<endl;
        return;
    }
    int requiredNum = sum / 3;

    if(b>requiredNum || a>requiredNum){
        cout<<"NO"<<endl;
        return;
    }

    else{
        cout<<"YES"<<endl;
        return;
    }
    
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