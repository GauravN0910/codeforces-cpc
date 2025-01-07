#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void dfs(int node, int parent, vector<int>& oneDegNodes, vector<vector<int>>& graph){
    for(auto neighbor:graph[node]){
        if(neighbor!=parent){
            dfs(neighbor, node, oneDegNodes, graph);
        }
    }

    if(graph[node].size()==1){
        oneDegNodes.push_back(node);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    vector<int> degree(n+1);
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    int degOne = 0;
    
    for(int i=1;i<=n;i++){
        if(degree[i]==1){
            degOne++;
        }
    }
    
    int ans = (degOne+1)/2;
    
    vector<int> oneDegNodes;
    dfs(1, 0, oneDegNodes, graph);

    int sz = oneDegNodes.size();
    cout<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<oneDegNodes[i]<<" "<<oneDegNodes[(i+ans)%sz]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}