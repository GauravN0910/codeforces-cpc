#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long helperFn(long long x, long long k){
    vector<long long> factors;
    for(long long i=1;i<=x;i++){
        if(x%i==0){
            factors.push_back(i);
        }
    }

    vector<long long> ans(x+1, 1e9);
    ans[1] = 0;
    for(auto X:factors){
        for(auto Y:factors){
            if(X%Y==0 && X/Y<=k){
                ans[X] = min(ans[X], ans[Y] + 1);
            }
        }
    }
    return ans[x];
}

void solve(){
    
    long long x, y, k;
    cin>>x>>y>>k;
    
    long long gcdVal = __gcd(x, y);
    x /= gcdVal;
    y /= gcdVal;

    long long ans = helperFn(x, k) + helperFn(y, k);

    if(ans>=1e9){
        ans = -1;
    }
    cout<<ans<<endl;
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