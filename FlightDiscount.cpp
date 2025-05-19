#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

vector<long long> dijkstra(long long src, vector<vector<pair<long long, long long>>>& graph, long long n){
    vector<long long> dist(n+1, LLONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()){
        long long node = pq.top().second;
        long long cost = pq.top().first;
        pq.pop();

        if(cost > dist[node]){
            continue;
        }

        for(auto [neighbor, w]: graph[node]){
            if(dist[node] + w < dist[neighbor]){
                dist[neighbor] = dist[node] + w;
                pq.push({dist[neighbor], neighbor});

            }
        }
    }

    return dist;
}

void solve(){
    long long n, m;
    cin>>n>>m;

    vector<vector<pair<long long, long long>>> graph(n+1);
    vector<vector<pair<long long, long long>>> revGraph(n+1);

    for(long long i=0;i<m;i++){
        long long u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        revGraph[v].push_back({u, w});
    }

    vector<long long> dist = dijkstra(1, graph, n);
    vector<long long> revDist = dijkstra(n, revGraph, n);

    long long ans = LLONG_MAX;
    for(long long i=1;i<=n;i++){
        for(auto [neighbor, w]: graph[i]){
            if(dist[i] != LLONG_MAX && revDist[neighbor] != LLONG_MAX){
                ans = min(ans, dist[i] + w/2 + revDist[neighbor]);
            }
        }
    }

    cout<<ans<<endl;
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