#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;

    long long add = 3;
    long long start = 1;
    long long numOperations = 1;

    while(start<n){
        start += add;
        add *= 2;
        numOperations++;
    }
    cout<<numOperations<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}