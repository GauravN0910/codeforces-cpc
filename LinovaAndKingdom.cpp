#include<bits/stdc++.h>
using namespace std;

long long dfs(long long node, long long level, vector<long long>& distance, vector<vector<long long>>& graph, vector<bool>& visited){
    visited[node] = 1;
    long long subTree = 0;

    for(auto neighbor:graph[node]){
        if(!visited[neighbor]){
            subTree += dfs(neighbor, level+1, distance, graph, visited);
        }
    }
    distance.push_back(level-subTree);
    return subTree + 1;
}

int main(){
    long long n, k;
    cin>>n>>k;
    vector<vector<long long>> graph(n+1, vector<long long>());
    long long ans = 0;
    for(long long i=1;i<n;i++){
        long long u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<long long> distance;
    vector<bool> visited(n+1);
    dfs(1, 0, distance, graph, visited);

    sort(distance.begin(), distance.end(), greater<long long>());

    for(long long i=0;i<k;i++){
        ans += distance[i];
    }
    cout<<ans<<endl;
}