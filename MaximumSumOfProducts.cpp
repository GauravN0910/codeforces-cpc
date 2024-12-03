#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<long long> a(n);
    vector<long long> b(n);

    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<n;i++){
        cin>>b[i];
    }

    vector<long long> prefixSum(n+1);
    
    for(long long i=1;i<=n;i++){
        prefixSum[i] = a[i-1]*b[i-1] + prefixSum[i-1];
    }

    long long ans = prefixSum[n];
    for(long long centre=0;centre<n;centre++){
        long long curSum = a[centre]*b[centre];
        for(long long l=centre-1, r=centre+1;l>=0 && r<n;--l, ++r){
            curSum += (a[l]*b[r]) + (a[r]*b[l]);
            ans = max(ans, curSum + prefixSum[l] + (prefixSum[n] - prefixSum[r+1]));
        }

        curSum = 0;
        for(long long l=centre, r=centre+1;l>=0 && r<n;--l, ++r){
            curSum += (a[l]*b[r]) + (a[r]*b[l]);
            ans = max(ans, curSum + prefixSum[l] + (prefixSum[n] - prefixSum[r+1]));
        }
    }

    cout<<ans<<endl;
}

int main(){
    long long t = 1;
    while(t--){
        solve();
    }
}