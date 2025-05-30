#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    int oneCount = 0;
    int zeroCount = 0;
    for(auto x:s){
        if(x=='1'){
            oneCount++;
        }
        else{
            zeroCount++;
        }
    }

    int extra = n/2 - k;
    if(oneCount<extra){
        cout<<"NO"<<endl;
        return;
    }
    oneCount -= extra;
    if(zeroCount<extra){
        cout<<"NO"<<endl;
        return;
    }
    zeroCount -= extra;

    if(oneCount%2==0 && zeroCount%2==0 && oneCount + zeroCount==2*k){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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