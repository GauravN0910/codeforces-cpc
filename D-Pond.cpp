#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

bool checkFn(vector<vector<long long>>& grid, long long mid, long long limit, long long n, long long k){
    vector<vector<long long>> prefixSum(n+1, vector<long long>(n+1, 0));
    
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            prefixSum[i][j] = (grid[i][j]<=mid);
        }
    }

    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            prefixSum[i][j] = prefixSum[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }

    for(long long i=1;i<=n-k+1;i++){
        for(long long j=1;j<=n-k+1;j++){
            long long sumOfBox = prefixSum[i+k-1][j+k-1] - prefixSum[i+k-1][j-1] - prefixSum[i-1][j+k-1] + prefixSum[i-1][j-1];
            if(sumOfBox>=limit){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    long long n, k;
    cin>>n>>k;

    vector<vector<long long>> grid(n+1, vector<long long>(n+1));
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            cin>>grid[i][j];
        }
    }

    long long limit = (k*k+1)/2;

    long long low = 0;
    long long high = 1e9;
    long long ans;

    while(low<=high){
        long long mid = low + (high-low)/2;
        if(checkFn(grid, mid, limit, n, k)){
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
    long long t = 1;
    while(t--){
        solve();
    }
}