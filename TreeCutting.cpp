#include<bits/stdc++.h>
using namespace std;

int cuts = 0;

void dfs(int node, int parent, vector<vector<int>>& adj, int mid, vector<int>& subSize){
    subSize[node] = 1;
    for(int neighbor:adj[node]){
        if(neighbor==parent)continue;
        dfs(neighbor, node, adj, mid, subSize);
        subSize[node] += subSize[neighbor];
    }
    if(subSize[node]>=mid){
        subSize[node] = 0;
        cuts++;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<vector<int>> adj(n+1, vector<int>());

        for(int i=1;i<n;i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int low = 1;
        int high = n;
        int ans = 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            vector<int> subSize(n+1);
            cuts = 0;
            dfs(1, 0, adj, mid, subSize);
            cuts--;
            if(cuts>=k){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        cout<<ans<<endl;
    }
}