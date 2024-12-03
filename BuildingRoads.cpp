#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int node){
    visited[node] = 1;
    for(auto neighbor:graph[node]){
        if(!visited[neighbor]){
            dfs(graph, visited, neighbor);
        }
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> visited(n+1);
    vector<vector<int>> graph(n+1, vector<int>());

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int prevNode = 0;
    vector<pair<int, int>> roads;
    for(int currNode=1;currNode<=n;currNode++){
        if(!visited[currNode]){
            roads.push_back({prevNode, currNode});
            dfs(graph, visited, currNode);
            prevNode = currNode;
        }
    }

    int ans = roads.size()-1;
    cout<<ans<<endl;
    for(int i=1;i<roads.size();i++){
        pair<int, int> road = roads[i];
        cout<<road.first<<" "<<road.second<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}