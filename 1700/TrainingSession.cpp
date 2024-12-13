#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> topic(n);
    vector<long long> difficulty(n);

    map<long long, long long> topicMap;
    map<long long, long long> difficultyMap;

    for(long long i=0;i<n;i++){
        cin>>topic[i]>>difficulty[i];
        topicMap[topic[i]]++;
        difficultyMap[difficulty[i]]++;
    }

    long long totalTriplets = ((n*(n-1)*(n-2))/6);
    long long badTriplets = 0;

    for(long long i=0;i<n;i++){
        badTriplets += (topicMap[topic[i]]-1) * (difficultyMap[difficulty[i]] - 1);
    }

    long long ans = totalTriplets - badTriplets;
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