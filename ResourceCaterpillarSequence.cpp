#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;

    vector<vector<long long>> graph(n+1);
    vector<long long>  degree(n+1);
    for(long long i=1;i<n;i++){
        long long u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    long long numLeaves = 0;
    for(long long i=1;i<=n;i++){
        if(degree[i]==1){
            numLeaves++;
        }
    }

    long long ans = numLeaves * (n-numLeaves);
    vector<long long> nonLeafDegree(n+1);
    long long numNoLeafNeighbors = 0;
    for(long long node=1;node<=n;node++){
        if(degree[node]>1){
            for(auto neighbor:graph[node]){
                if(degree[neighbor]>1){
                    nonLeafDegree[node]++;
                }
            }
            if(degree[node]==nonLeafDegree[node]){
                numNoLeafNeighbors++;
            }
        }
    }

    for(long long node=1;node<=n;node++){
        if(degree[node]>1 && degree[node]!=nonLeafDegree[node]){
            ans += numNoLeafNeighbors * (nonLeafDegree[node] - 1); /*Subtract 1 to account for the path being taken to one of the NoLeaFNeighbor Nodes*/
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