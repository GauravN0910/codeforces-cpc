#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void dfs2(vector<vector<long long>>& graph, vector<long long>& values, vector<long long>& dp, long long node, long long parent){
    for(auto neighbor:graph[node]){
        if(neighbor!=parent){
            dfs2(graph, values, dp, neighbor, node);
            dp[node] += dp[neighbor];
            if(values[neighbor]>values[node]){
                dp[node] += values[neighbor] - values[node];
            }
        }
    }
}

void dfs(vector<vector<long long>>& graph, vector<long long>& left, vector<long long>& right, vector<long long>& values, long long node, long long parent){
    long long maxVal = 0;
    for(auto neighbor:graph[node]){
        if(neighbor!=parent){
            dfs(graph, left, right, values, neighbor, node);
            maxVal = max(maxVal, values[neighbor]);
        }
    }
    values[node] = max(left[node], min(right[node], maxVal));
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> left(n+1);
    vector<long long> right(n+1);
    for(long long i=1;i<=n;i++){
        cin>>left[i];
        cin>>right[i];
    }

    vector<vector<long long>> graph(n+1);
    for(long long i=1;i<n;i++){
        long long u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<long long> values(n+1);
    dfs(graph, left, right, values, 1, 0);

    vector<long long> dp(n+1);

    dfs2(graph, values, dp, 1, 0);
    long long ans = dp[1] + values[1];
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
    
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}