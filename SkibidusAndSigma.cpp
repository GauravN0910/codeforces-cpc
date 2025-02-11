#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, m;
    cin>>n>>m;
    vector<vector<long long>> grid(n, vector<long long>(m));
    vector<long long> rowSums(n);
    long long ans = 0;
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            cin>>grid[i][j];
            rowSums[i] += grid[i][j];
            ans += rowSums[i];
        }
    }

    sort(rowSums.begin(), rowSums.end());
    for(long long i=0;i<n;i++){
        ans += rowSums[i] * i * m;
    }
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