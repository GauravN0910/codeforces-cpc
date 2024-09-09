#include<bits/stdc++.h>
using namespace std;

double dfs(vector<vector<int>> &graph, int parent, int node){
    double paths = 0;
    double length = 0;
    for(auto neighbor:graph[node]){
        if(neighbor!=parent){
            paths++;
            length += dfs(graph, node, neighbor);
        }
    }
    return paths?length/paths+1:0;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1, vector<int>());

    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    printf("%.8lf",dfs(graph, 0, 1));
}