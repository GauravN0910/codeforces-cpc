#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int a1, a2, a4, a5;
    cin>>a1>>a2>>a4>>a5;

    set<int> x;
    x.insert(a2+a1);
    x.insert(a4-a2);
    x.insert(a5-a4);

    int n = x.size();
    int ans = 4 - n;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}