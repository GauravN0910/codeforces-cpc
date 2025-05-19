#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m, l;
    cin>>n>>m>>l;

    int sum = 0;
    int minOdd = 2e9 + 1;
    for(int i=0;i<l;i++){
        int x;
        cin>>x;
        sum += x;
        if(x%2){
            minOdd = min(minOdd, x);
        }
    }

    vector<vector<int>> graph(n+1, vector<int>());
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> distance(n+1, vector<int>(2, 2e9+1));
    queue<pair<int, int>> q;
    q.push({1, 0});
    distance[1][0] = 0;
    while(!q.empty()){
        auto [node, parity] = q.front();
        q.pop();

        for(auto neighbor:graph[node]){
            if(distance[neighbor][!parity]>distance[node][parity] + 1){
                distance[neighbor][!parity] = distance[node][parity] + 1;
                q.push({neighbor, !parity});
            }
        }
    }

    vector<int> ans(n+1);

    for(int i=1;i<=n;i++){
        for(int parity=0;parity<2;parity++){
            int newSum = sum - (parity == sum%2?0:minOdd);
            if(newSum>=distance[i][parity]){
                ans[i] = 1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i];
    }
    cout<<endl;
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