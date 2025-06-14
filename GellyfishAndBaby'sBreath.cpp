#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long pow2[100005];

void precompute(){
    pow2[0] = 1;
    for(long long i=1;i<=100000;i++){
        pow2[i] = (pow2[i-1] * 2) % mod;
    }
}

void solve(){
    long long n;
    cin>>n;

    vector<long long> permA(n);
    vector<long long> permB(n);
    map<long long, long long> idxA;
    map<long long, long long> idxB;
    for(long long i=0;i<n;i++){
        cin>>permA[i];
        idxA[permA[i]] = i;
    }
    for(long long i=0;i<n;i++){
        cin>>permB[i];
        idxB[permB[i]] = i;
    }
    long long maxElem = 0;

    vector<long long> ans(n);
    priority_queue<long long> pq;
    for(long long i=0;i<n;i++){
        maxElem = max({maxElem, permA[i], permB[i]});

        long long a = maxElem;
        long long b = -1;

        if(idxA[a]<=i){
            long long idx = idxA[a];
            long long otherIdx = i - idx;
            b = max(b, permB[otherIdx]);
        }

        if(idxB[a]<=i){
            long long idx = idxB[a];
            long long otherIdx = i - idx;
            b = max(b, permA[otherIdx]);
        }

        ans[i] = (pow2[a] + pow2[b] + mod)%mod;

    }

    for(long long i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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