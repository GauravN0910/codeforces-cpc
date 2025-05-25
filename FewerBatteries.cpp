#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;


bool checkerFn(vector<vector<pair<long long, long long>>>& graph, vector<long long>& numBatteries, long long mid, long long n){
    vector<long long> maxBatteries(n+1, -1);
    maxBatteries[1] = numBatteries[1];

    for(long long i=1;i<=n;i++){
        if(maxBatteries[i] < 0){
            continue;
        }
        for(auto [neighbor, weight] : graph[i]){
            if(weight>mid){
                continue;
            }
            if(maxBatteries[i]<weight){
                continue;
            }
            maxBatteries[neighbor] = max(maxBatteries[neighbor], maxBatteries[i] + numBatteries[neighbor]);
        }   
    }
    return maxBatteries[n]>=0;
}


void solve(){
    long long numNodes, numEdges;
    cin>>numNodes>>numEdges;

    vector<long long> numBatteries(numNodes + 1);
    for(long long i=1;i<=numNodes;i++){
        cin>>numBatteries[i];
    }

    vector<vector<pair<long long, long long>>> graph(numNodes + 1);
    for(long long i=0;i<numEdges;i++){
        long long u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
    }

    long long low = 1;
    long long high = 1e9;
    long long ans = -1;
    while(low<=high){
        long long mid = low + (high - low) / 2;
        if(checkerFn(graph, numBatteries, mid, numNodes)){
            ans = mid;
            high = mid - 1;
        } else {
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