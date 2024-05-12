#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long ans = 2*n - __builtin_popcountll(n);
        cout<<ans<<endl;
    }
}