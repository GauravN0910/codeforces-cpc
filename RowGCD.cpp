#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, m;
    cin>>n>>m;
    long long gcdA = 0;
    long long firstA;
    cin>>firstA;
    for(long long i=1;i<n;i++){
        long long x;
        cin>>x;
        gcdA = __gcd(gcdA, abs(firstA - x));
    }

    for(long long i=0;i<m;i++){
        long long x;
        cin>>x;
        long long ans = __gcd(gcdA, firstA + x);
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main(){
    solve();
}