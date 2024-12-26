#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, q;
    cin>>n>>q;

    vector<vector<long long>> matrix(n+1, vector<long long>(n+1));
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            cin>>matrix[i][j];
        }
    }

    vector<vector<long long>> prefixSum(n+1, vector<long long>(n+1));
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            prefixSum[i][j] = matrix[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }

    vector<vector<long long>> prefixSumX(n+1, vector<long long>(n+1));
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            prefixSumX[i][j] = matrix[i][j]*(i-1) + prefixSumX[i-1][j] + prefixSumX[i][j-1] - prefixSumX[i-1][j-1];
        }
    }
    
    vector<vector<long long>> prefixSumY(n+1, vector<long long>(n+1));
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            prefixSumY[i][j] = matrix[i][j]*(j-1) + prefixSumY[i-1][j] + prefixSumY[i][j-1] - prefixSumY[i-1][j-1];
        }
    }

    while(q--){
        long long x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        long long sz = y2 - y1 + 1; 

        long long ans = 0;
        long long sum = (prefixSum[x2][y2] - prefixSum[x2][y1-1] - prefixSum[x1-1][y2] + prefixSum[x1-1][y1-1]);
        long long sumX = (prefixSumX[x2][y2] - prefixSumX[x2][y1-1] - prefixSumX[x1-1][y2] + prefixSumX[x1-1][y1-1]);
        long long sumY = (prefixSumY[x2][y2] - prefixSumY[x2][y1-1] - prefixSumY[x1-1][y2] + prefixSumY[x1-1][y1-1]);

        ans += (sumX - (x1-1)*sum) * (sz);
        ans += (sumY - (y1-1)*sum);
        ans += sum;
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}