#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int maxVal, maxValNode;

void dfs(vector<vector<int>>& graph, vector<int>& values, map<int, int>& revMap, int node, int parent){
    for(auto neighbor:graph[node]){
        if(neighbor!=parent){
            dfs(graph, values, revMap, neighbor, node);
        }
    }

    auto greater = revMap.lower_bound(values[node]);
    if(greater!=revMap.begin()){
        greater--;
        if(greater->first>maxVal){
            maxVal = greater->first;
            maxValNode = greater->second;
        }
    }
    revMap[values[node]] = node;
}

void solve(){
    int n;
    cin>>n;
    vector<int> values(n+1);
    vector<vector<int>> graph(n+1);
    for(int i=1;i<=n;i++){
        cin>>values[i];
    }

    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    maxVal = 0;
    maxValNode = 0;
    map<int, int> revMap;
    dfs(graph, values, revMap, 1, 0);
    for(int i=1;i<=n;i++){
        reverse(graph[i].begin(), graph[i].end());
    }
    revMap.clear();
    dfs(graph, values, revMap, 1, 0);
    cout<<maxValNode<<endl;
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