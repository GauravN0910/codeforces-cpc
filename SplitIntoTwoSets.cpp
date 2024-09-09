#include<bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>>& graph, vector<int>& visited){
    visited[node] = 1;
    for(auto neighbor:graph[node]){
        if(!visited[neighbor]){
            return 1 + dfs(neighbor, graph, visited);
        }
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> graph(n+1, vector<int>());
        bool flag = true;
        
        for(int i=1;i<=n;i++){
            int x, y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
            if(x==y || graph[x].size()>2 || graph[y].size()>2){
                flag = false;
            }
        }

        vector<int> visited(n+1);

        for(int i=1;i<=n;i++){
            if(!visited[i]){
                if(dfs(i, graph, visited)%2){
                    flag = false;
                }
            }
        }
        
        if(!flag){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}