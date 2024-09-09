#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        map<int, set<int>> graph;
        vector<int> degree(n+1);
        for(int i=1;i<n;i++){
            int u, v;
            cin>>u>>v;
            degree[u]++;
            degree[v]++;
            graph[u].insert(v);
            graph[v].insert(u);
        }   

        queue<int> leaves;

        for(int i=1;i<=n;i++){
            if(degree[i]==1 || degree[i]==0){
                leaves.push(i);
            }
        }
        int ans = 0;

        while(!leaves.empty() && k){
            int size = leaves.size();
            ans += size;
            while(size--){
                int node = leaves.front();
                leaves.pop();
                for(auto neighbor:graph[node]){
                    graph[neighbor].erase(node);
                    degree[neighbor]--;
                    if(degree[neighbor]==1){
                        leaves.push(neighbor);
                    }
                }
                graph.erase(node);
            }
            k--;
        }
        ans = n - ans;
        cout<<ans<<endl;
    }

}