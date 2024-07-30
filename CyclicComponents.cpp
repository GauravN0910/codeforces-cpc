#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int node, vector<int>& component){
    visited[node] = 1;
    for(auto neighbor:graph[node]){
        if(!visited[neighbor]){
            dfs(graph, visited, neighbor, component);
        }
    }
    component.push_back(node);
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1, vector<int>());
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n+1);
    vector<vector<int>> components;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(graph, visited, i, component);
            components.push_back(component);
        }
    }

    int ans = 0;
    for(auto component:components){
        int flag = true;
        for(auto node:component){
            if(graph[node].size()!=2){
                flag = false;
            }
        }
        ans += flag;
    }
    cout<<ans<<endl;
}