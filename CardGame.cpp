#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;


long long factorial[65];
long long dpAlice[65];
long long dpBob[65];

long long binExp(long long n, long long pow){
    if(pow==0){
        return 1;
    }
    long long ans = binExp(n, pow/2);
    if(pow%2){
        return ((ans*ans)%mod * n)%mod;
    }
    return (ans*ans)%mod;
}

long long invMod(long long n){
    return (binExp(n, mod-2))%mod;
}

long long nCr(long long n, long long r){
    if(r > n){
        return 0;
    }
    long long ans = factorial[n];
    long long denominator = (factorial[r]*factorial[n-r])%mod;
    ans = (ans*invMod(denominator))%mod;
    return ans%mod;
}

void precompute(){
    factorial[0] = 1;
    for(long long i=1;i<65;i++){
        factorial[i] = (factorial[i-1]*i)%mod;
    }

    dpAlice[2] = 1;
    dpBob[2] = 0;
    for(long long i=4;i<=60;i+=2){
        dpAlice[i] = (dpBob[i-2] + nCr(i-1, i/2))%mod;
        dpBob[i] = (dpAlice[i-2] + nCr(i-2, i/2))%mod;
    }
}

void solve(){
    long long n;
    cin>>n;
    cout<<dpAlice[n]<<" "<<dpBob[n]<<" "<<1<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    precompute();
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}