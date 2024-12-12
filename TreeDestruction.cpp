#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int ans;

int dfs(vector<vector<int>>& graph, vector<int>& degree, int node, int parent){
    int retVal = degree[node]-1;
    ans = max(degree[node], ans);

    vector<int> branches;

    for(auto neighbor:graph[node]){
        if(neighbor==parent){
            continue;
        }

        int x = dfs(graph, degree, neighbor, node);
        branches.push_back(x);
        ans = max(ans, x + degree[node] - 1);
        retVal = max(retVal, x + degree[node] - 2);
    }  

    sort(branches.rbegin(), branches.rend());

    if(branches.size()>=2){
        ans = max(ans, branches[0] + branches[1] + degree[node] - 2);
    }
    return retVal;
}

void solve(){
    int n;
    cin>>n;

    vector<vector<int>> graph(n+1);
    vector<int> degree(n+1);
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ans = 0;
    dfs(graph, degree, 1, 0);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}