#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>> graph(n+1);
	vector<vector<int>> revGraph(n+1);
	vector<int> inDeg(n+1);

	for(int i=0;i<m;i++){
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
		revGraph[v].push_back(u);
		inDeg[v]++;
	}

	queue<int> q;
	for(int i=1;i<=n;i++){
		if(inDeg[i]==0){
			q.push(i);
		}
	}

	vector<int> dp(n+1);
	dp[1] = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto neighbor:graph[node]){
			inDeg[neighbor]--;
			if(inDeg[neighbor]==0){
				q.push(neighbor);
			}
		}

		for(auto parent:revGraph[node]){
			dp[node] = (dp[node] + dp[parent])%mod;
		}
	}
	cout<<dp[n]<<endl;
	return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t = 1;
    while(t--){
        solve();
    }
}
