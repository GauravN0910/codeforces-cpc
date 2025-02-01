#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

unordered_set<long long> xorVals;
long long xorValue;

void dfs(vector<long long>& stones, vector<long long>& sumVals, long long idx, long long numBags){
    long long n = stones.size();
    if(idx==n){
        xorVals.insert(xorValue);
        return;
    }
    for(long long i=0;i<=numBags;i++){
        xorValue ^= sumVals[i];
        sumVals[i] += stones[idx];
        xorValue ^= sumVals[i];
        if(i==numBags){
            dfs(stones, sumVals, idx+1, numBags+1);
        }
        else{
            dfs(stones, sumVals, idx+1, numBags);
        }
        xorValue ^= sumVals[i];
        sumVals[i] -= stones[idx];
        xorValue ^= sumVals[i];
    }
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> stones(n);
    for(long long i=0;i<n;i++){
        cin>>stones[i];
    }
    vector<long long> sumVals(n);
    for(long long i=0;i<n;i++){
        sumVals[i] = 0;
    }

    xorValue = 0;
    dfs(stones, sumVals, 0, 0);
    long long ans = xorVals.size();
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t = 1;
    while(t--){
        solve();
    }
}