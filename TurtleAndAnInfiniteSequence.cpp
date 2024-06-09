#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        long long ans = 0;
        for(long long i=max(n-m, 0ll);i<=m+n;i++){
            ans = ans|i;
            i = ans;
        }
        cout<<ans<<endl;
    }
}