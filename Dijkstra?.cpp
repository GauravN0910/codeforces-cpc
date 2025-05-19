#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;


void printAns(vector<long long>& parent, long long node){
    if(node == -1){
        return;
    }
    printAns(parent, parent[node]);
    cout<<node<<" ";
}

void solve(){
    long long n, m;
    cin>>n>>m;

    vector<vector<pair<long long, long long>>> graph(n+1);
    map<pair<long long, long long>, long long> edgeMap;
    for(long long i=0;i<m;i++){
        long long u, v, w;
        cin>>u>>v>>w;
        if(edgeMap.find({u, v}) == edgeMap.end() || (edgeMap[{u, v}] > w)){
            edgeMap[{u, v}] = w;
            edgeMap[{v, u}] = w;
        }
    }

    for(auto elem:edgeMap){
        graph[elem.first.first].push_back({elem.first.second, elem.second}); 
        graph[elem.first.first].push_back({elem.first.second, elem.second}); 
    }

    vector<long long> dist(n+1, 1e18);
    vector<long long> parent(n+1, -1);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        long long d = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        if(d>dist[node]){
            continue;
        }

        for(auto edge: graph[node]){
            long long nextNode = edge.first;
            long long weight = edge.second;

            if(dist[node] + weight < dist[nextNode]){
                dist[nextNode] = dist[node] + weight;
                parent[nextNode] = node;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    if(dist[n] == 1e18){
        cout<<"-1"<<"\n";
        return;
    }

    printAns(parent, n);
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t = 1;
    while(t--){
        solve();
    }
}