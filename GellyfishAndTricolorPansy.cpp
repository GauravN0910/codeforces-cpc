#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    int minG = min(a, c);
    int minF = min(b, d);

    if(minG>=minF){
        cout<<"Gellyfish"<<endl;
        return;
    }
    else{
        cout<<"Flower"<<endl;
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