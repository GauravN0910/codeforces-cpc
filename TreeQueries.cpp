#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int timeVal;

void dfs(int node, int parentNode, vector<vector<int>>& graph, vector<int>& parent, vector<int>& depth, vector<int>& timeIn, vector<int>& timeOut){
    parent[node] = parentNode;
    timeIn[node] = timeVal++;
    for(auto neighbor:graph[node]){
        if(neighbor!=parentNode){
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node, graph, parent, depth, timeIn, timeOut);
        }
    }
    timeOut[node] = timeVal++;
}

bool isAncestor(int x, int y, vector<int>& timeIn, vector<int>& timeOut){
    return timeIn[x]<=timeIn[y] && timeOut[x]>=timeOut[y];
}

void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1);
    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    vector<int> parent(n+1);
    vector<int> depth(n+1);
    vector<int> timeIn(n+1);
    vector<int> timeOut(n+1);
    timeVal = 0;
    dfs(1, 0, graph, parent, depth, timeIn, timeOut);

    for(int i=0;i<m;i++){
        int k;
        cin>>k;

        vector<int> nodes;
        while(k--){
            int x;
            cin>>x;
            nodes.push_back(x);
        }

        int deepest = nodes[0];
        for(auto node:nodes){
            if(depth[node]>depth[deepest]){
                deepest = node;
            }
        }

        for(auto& node:nodes){
            if(node==deepest){
                continue;
            }
            if(parent[node]!=0){
                node = parent[node];
            }
        }


        bool flag = true;
        for(auto node:nodes){
            flag &= isAncestor(node, deepest, timeIn, timeOut);
        }

        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t = 1;
    while(t--){
        solve();
    }
}