#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

pair<long long, long long> dfs(long long l, long long r, long long k){
    if(r-l+1<k){
        return {0, 0};
    }
    if(r-l+1==1){
        return {l, 1};
    }

    long long mid = (l + r)/2;
    if((r-l+1)%2==0){
        auto [leftAndMidResult, numSegments] = dfs(l, mid, k);
        long long rightResult = leftAndMidResult;
        long long ans = rightResult + leftAndMidResult + mid * numSegments;
        long long newSegments = 2 * numSegments;
        return {ans, newSegments};
    }
    else{
        auto [leftAndMidResult, numSegments] = dfs(l, mid - 1, k);
        long long rightResult = leftAndMidResult;
        long long ans = mid + rightResult + leftAndMidResult + mid * numSegments;
        long long newSegments = 2 * numSegments + 1;
        return {ans, newSegments};
    }
}

void solve(){
    long long n, k;
    cin>>n>>k;
    auto [ans, numSegments] = dfs(1, n, k);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}