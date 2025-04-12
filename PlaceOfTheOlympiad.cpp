#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long maxDesks(long long m, long long mid){
    if(mid>=m){
        return m;
    }

    long long numBenches = (m + 1) / (mid + 1);
    long long type1 = min(numBenches * mid, m - numBenches + 1);
    long long type2 = 0;
    if(numBenches <= m){
        type2 = min((numBenches + 1) * mid, m - (numBenches + 1) + 1);
    }
    return max(type1, type2);
}

bool checkerFn(long long mid, long long n, long long m, long long k){
    long long maxDesksPerRow = maxDesks(m, mid);
    return (maxDesksPerRow*n >=k);
}

void solve(){
    long long n, m, k;
    cin>>n>>m>>k;

    long long low = 1;
    long long high = m;
    long long ans = m;
    while(low<=high){
        long long mid = low + (high - low)/2;
        if(checkerFn(mid, n, m, k)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
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