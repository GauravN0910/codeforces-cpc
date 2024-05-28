#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& parent, vector<int>& distance){
    for(auto neighbor:adj[node]){
        if(parent[node]!=neighbor){
            parent[neighbor] = node;
            distance[neighbor] = distance[node] + 1;
            dfs(neighbor, adj, parent, distance);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, a, b;
        cin>>n>>a>>b;
        vector<vector<int>> adj(n+1, vector<int>());
        for(int i=1;i<n;i++){
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> parent(n+1, 0);
        vector<int> distance(n+1, 0);
        int ans = 0;
        dfs(a, adj, parent, distance);
        ans += (distance[b]+1)/2;
        for(int i=1;i<=ans;i++){
            b = parent[b];
        }

        ans += 2*(n-1);
        for(int i=1;i<=n;i++){
            distance[i] = 0;
            parent[i] = 0;
        }
        dfs(b, adj, parent, distance);
        ans -= *max_element(distance.begin(), distance.end());
        cout<<ans<<endl;
    }
}