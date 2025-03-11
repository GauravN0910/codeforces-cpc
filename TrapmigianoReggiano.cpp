#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void dfs(vector<vector<int>>& graph, vector<int>& distance, int node, int parent){
    distance[node] = distance[parent] + 1;
    for(auto neighbor:graph[node]){
        if(parent!=neighbor){
            dfs(graph, distance, neighbor, node);
        }
    }
}

void solve(){
    int n, start, end;
    cin>>n>>start>>end;
    vector<vector<int>> graph(n+1, vector<int>());
    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> distance(n+1, -1);
    dfs(graph, distance, end, 0);

    vector<pair<int, int>> sortDistance;
    for(int i=1;i<=n;i++){
        sortDistance.push_back({distance[i], i});
    }

    sort(sortDistance.begin(), sortDistance.end());
    reverse(sortDistance.begin(), sortDistance.end());
    for(auto [_, node]:sortDistance){
        cout<<node<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}