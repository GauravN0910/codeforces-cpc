#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, int src, int dest){
    if(src==dest){
        return true;
    }

    for(auto neighbor:adj[src]){
        if(dfs(adj, neighbor, dest)){
            return true;
        }
    }
    return false;
}

void solve(){
    int n, t;
    cin>>n>>t;

    vector<vector<int>> adj(n, vector<int>());
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        adj[i-1].push_back(i-1+a);
    }

    if(dfs(adj, 0, t-1)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}

int main(){
    solve();
}