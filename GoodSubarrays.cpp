#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> prefixSum(n+1);

    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        prefixSum[i] = c-'0';
        prefixSum[i] += prefixSum[i-1];
    }

    map<long long, long long> prefixIdx;
    for(int i=0;i<=n;i++){
        prefixIdx[prefixSum[i] - i]++;
    }

    long long ans = 0;
    for(auto [_, x]:prefixIdx){
        ans += (x*(x-1))/2;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}