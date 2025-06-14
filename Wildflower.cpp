#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long binExp(long long base, long long power){
	if(power==0){
		return 1;
	}

	long long ans = binExp(base, power/2);

	if(power%2){
		return ((ans * ans)%mod * base)%mod;
	}
	return (ans*ans)%mod;
}

void dfs(long long node, long long parent, vector<vector<long long>>& graph, vector<long long>& depth){
	for(auto neighbor:graph[node]){
		if(neighbor!=parent){
			depth[neighbor] = depth[node] + 1;
			dfs(neighbor, node, graph, depth);
		}
	}
}

void solve(){
	long long n;
	cin>>n;

	vector<vector<long long>> graph(n+1);
	vector<long long> degree(n+1);
	for(long long i=1;i<n;i++){
		long long u, v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}

	long long leafCount = 0;
	for(long long i=2;i<=n;i++){
		if(degree[i]==1){
			leafCount++;
		}
	}

	
	if(leafCount>=3){
		cout<<0<<endl;
		return;
	}

	long long branchingNode = 0;
	for(long long i=1;i<=n;i++){
		if(i==1 && degree[i]==2){
			branchingNode = i;
			break;
		}
		if(degree[i]==3){
			branchingNode = i;
			break;
		}
	}

	if(leafCount==1){
		long long ans = binExp(2, n);
		cout<<ans<<endl;
		return;
	}

	vector<long long> depth(n+1, 1);
	dfs(1, 0, graph, depth);

	long long depthX = 0;
	long long depthY = 0;

	for(long long i=2;i<=n;i++){
		if(degree[i]==1){
			if(depthX==0){
				depthX = depth[i];
			}
			else if(depthY==0){
				depthY = depth[i];
				break;
			}
		}
	}

	if(depthX==depthY){
		long long ans = binExp(2, depth[branchingNode] + 1);
		cout<<ans<<endl;
		return;
	}
	else{
		if(depthX>depthY){
			swap(depthX, depthY);
		}

		long long ans = ((binExp(2, depthY - depthX) + binExp(2, depthY - depthX - 1))%mod * binExp(2, depth[branchingNode]))%mod;
		cout<<ans<<endl;
		return;
	}
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
