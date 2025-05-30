#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void dfs(long long node, long long parent, vector<vector<long long>>& graph, 
vector<long long>& minPrefix, vector<long long>& maxPrefix, vector<long long>& danger){
	for(auto neighbor:graph[node]){
		if(neighbor!=parent){
			minPrefix[neighbor] = min(danger[neighbor], danger[neighbor] - maxPrefix[node]);
			maxPrefix[neighbor] = max(danger[neighbor], danger[neighbor] - minPrefix[node]);
			dfs(neighbor, node, graph, minPrefix, maxPrefix, danger);
		}
	}
}
	
void solve(){
	long long n;
	cin>>n;

	vector<long long> danger(n+1);
	for(long long i=1;i<=n;i++){
		cin>>danger[i];
	}

	vector<vector<long long>> graph(n+1, vector<long long>());
	for(long long i=1;i<n;i++){
		long long u, v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<long long> minPrefix(n+1);
	vector<long long> maxPrefix(n+1);
	minPrefix[1] = danger[1];
	maxPrefix[1] = danger[1];

	dfs(1, 0, graph, minPrefix, maxPrefix, danger);
	for(long long i=1;i<=n;i++){
		cout<<maxPrefix[i]<<" ";
	}
	cout<<endl;
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
