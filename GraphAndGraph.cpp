#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int nodes, sourceA, sourceB;
    cin>>nodes>>sourceA>>sourceB;

    
    vector<vector<int>> graphA(nodes+1);
    vector<vector<int>> graphB(nodes+1);
    
    vector<vector<int>> adjMatrixA(nodes+1, vector<int>(nodes+1, 0));
    vector<vector<int>> adjMatrixB(nodes+1, vector<int>(nodes+1, 0));
    
    
    int edgesA;
    cin>>edgesA;
    for(int i=0;i<edgesA;i++){
        int u, v;
        cin>>u>>v;
        graphA[u].push_back(v);
        graphA[v].push_back(u);
        adjMatrixA[u][v] = 1;
        adjMatrixA[v][u] = 1;
    }

    int edgesB;
    cin>>edgesB;
    for(int i=0;i<edgesB;i++){
        int u, v;
        cin>>u>>v;
        graphB[u].push_back(v);
        graphB[v].push_back(u);
        adjMatrixB[u][v] = 1;
        adjMatrixB[v][u] = 1;
    }

    set<int> validNodes; 
    for(int i=1;i<=nodes;i++){
        for(int j=i+1;j<=nodes;j++){
            if(adjMatrixA[i][j] && adjMatrixB[i][j]){
                validNodes.insert(i);
                validNodes.insert(j);
            }
        }
    }


    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> distance(nodes+1, vector<int>(nodes+1, 1e9));
    distance[sourceA][sourceB] = 0;
    pq.push({0, {sourceA, sourceB}});

    while(!pq.empty()){
        auto topElem = pq.top();
        pq.pop();

        int cost = topElem.first;
        int nodeA = topElem.second.first;
        int nodeB = topElem.second.second;

        for(auto neighborA:graphA[nodeA]){
            for(auto neighborB:graphB[nodeB]){
                int travelCost = abs(neighborA - neighborB);
                if(distance[nodeA][nodeB] + travelCost < distance[neighborA][neighborB]){
                    distance[neighborA][neighborB] = distance[nodeA][nodeB] + travelCost;
                    pq.push({distance[neighborA][neighborB], {neighborA, neighborB}});
                }
            }
        }
    }

    int ans = 1e9;
    for(auto node:validNodes){
        ans = min(ans, distance[node][node]);
    }

    if(ans == 1e9){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
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