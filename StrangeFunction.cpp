#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    long long ans = 0;
    long long lcm = 1;
    long long i = 1;
    while(true){
        lcm = (lcm*i)/__gcd(lcm, i);
        if(lcm>n){
            break;    
        }
        ans = (ans + n/lcm)%mod;
        i++;
    }
    cout<<(ans + n)%mod<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}