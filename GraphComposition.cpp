#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void dfsG(map<long long, long long>& componentMap, vector<vector<long long>>& graph, vector<long long>& visited, long long node, long long compNum){
    visited[node] = 1;
    componentMap[node] = compNum;
    for(auto neighbor:graph[node]){
        if(!visited[neighbor]){
            dfsG(componentMap, graph, visited, neighbor, compNum);
        }
    }
}

void dfsF(map<long long, long long>& componentMap, vector<vector<long long>>& graph, vector<long long>& visited, long long node, long long compNum){
    visited[node] = 1;
    componentMap[node] = compNum;
    for(auto neighbor:graph[node]){
        if(!visited[neighbor] && componentMap[neighbor]==compNum){
            dfsF(componentMap, graph, visited, neighbor, compNum);
        }
    }
}


void solve(){
    long long n, mF, mG;
    cin>>n>>mF>>mG;
    map<long long, long long> componentMap;
    vector<vector<long long>> graphF(n+1);
    vector<vector<long long>> graphG(n+1);
    vector<pair<long long, long long>> edges;

    for(long long i=0;i<mF;i++){
        long long u, v;
        cin>>u>>v;
        graphF[u].push_back(v);
        graphF[v].push_back(u);
        edges.push_back({u, v});
    }

    for(long long i=0;i<mG;i++){
        long long u, v;
        cin>>u>>v;
        graphG[u].push_back(v);
        graphG[v].push_back(u);
    }

    long long compNum = 1;
    vector<long long> visitedG(n+1);
    for(long long node=1;node<=n;node++){
        if(!visitedG[node]){
            dfsG(componentMap, graphG, visitedG, node, compNum);
            compNum++;
        }
    }

    /* Number of edges to be removed in F */
    long long ans = 0;
    for(auto [x, y]:edges){
        if(componentMap[x]!=componentMap[y]){
            ans += 1;
        }
    }

    vector<long long> visitedF(n+1);
    map<long long, long long> compCount;
    for(long long node=1;node<=n;node++){
        if(!visitedF[node]){
            dfsF(componentMap, graphF, visitedF, node, componentMap[node]);
            compCount[componentMap[node]]++;
        }
    }

    /* Number of edges to be added in F */
    for(auto elem:compCount){
        ans += elem.second - 1;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}