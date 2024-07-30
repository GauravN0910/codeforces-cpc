#include<bits/stdc++.h>
using namespace std;


int ans = 0;

void dfs(vector<vector<int>>& graph, vector<int>& cats, int node, int parent, int totalCats, int m){
    if(cats[node]){
        totalCats++;
    }
    else{
        totalCats = 0;
    }
    if(totalCats>m){
        return;
    }
    
    if(graph[node].size()==1 && node!=1){
        ans++;
    }

    for(auto neighbor:graph[node]){
        if(neighbor!=parent){
            dfs(graph, cats, neighbor, node, totalCats, m);
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> cats(n+1);
    for(int i=1;i<=n;i++){
        cin>>cats[i];
    }

    vector<vector<int>> graph(n+1, vector<int>());
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(graph, cats, 1, 0, 0, m);
    cout<<ans<<endl;
}