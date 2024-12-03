#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> firstRow(n);
    vector<int> secondRow(n);

    for(int i=0;i<n;i++){
        cin>>firstRow[i];
    }

    for(int i=0;i<n;i++){
        cin>>secondRow[i];
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        ans += max(firstRow[i], secondRow[i]);
    }

    
    int bestLow = INT_MIN;
    for(int i=0;i<n;i++){
        bestLow = max(bestLow, min(firstRow[i], secondRow[i]));
    }
    ans += bestLow;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}