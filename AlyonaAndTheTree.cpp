#include<bits/stdc++.h>
using namespace std;

int subtreeSize[100005];
int ans = 0;

void dfs(vector<vector<pair<int, int>>>& graph, int node, int distance, vector<int>& nodeValues){
    if(distance<0){
        distance = 0;
    }

    if(distance>nodeValues[node]){
        ans += subtreeSize[node];
        return;
    }

    for(auto [neighbor, cost]:graph[node]){
        dfs(graph, neighbor, distance + cost, nodeValues);
    }
}

void dfssubtreeSize(vector<vector<pair<int, int>>>& graph, int node){
    subtreeSize[node] = 1;
    for(auto [neighbor, weight]: graph[node]){
        dfssubtreeSize(graph, neighbor);
        subtreeSize[node] += subtreeSize[neighbor];
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> nodeValues(n+1);
    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());
    for(int i=1;i<=n;i++){
        cin>>nodeValues[i];
    }

    for(int i=2;i<=n;i++){
        int x, cost;
        cin>>x>>cost;
        graph[x].push_back({i, cost});
    }

    dfssubtreeSize(graph, 1);
    dfs(graph, 1, 0, nodeValues);
    cout<<ans<<endl;
}