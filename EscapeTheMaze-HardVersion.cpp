#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int finalAns;
bool leafReachable;

void dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& minDistance, vector<int>& depth){
	for(auto neighbor:graph[node]){
		if(neighbor==parent){
			continue;
		}
		depth[neighbor] = depth[node] + 1;
		dfs(neighbor, node, graph, minDistance, depth);
		minDistance[node] = min(minDistance[node], minDistance[neighbor] + 1);
	}
}

void dfsAns(int node, int parent, vector<vector<int>>& graph, vector<int>& minDistance, vector<int>& depth){
	int degree = graph[node].size();
	if(degree==1 && graph[node][0] == parent){
		leafReachable = true;
		return;
	}

	for(auto neighbor:graph[node]){
		if(neighbor==parent){
			continue;
		}
		if(depth[neighbor]<minDistance[neighbor]){
			dfsAns(neighbor, node, graph, minDistance, depth);
		}
		else{
			finalAns++;
		}
	}
}

void solve(){
	int n, k;
	cin>>n>>k;
	vector<vector<int>> graph(n+1);
	vector<int> minDistance(n+1, n);
	vector<int> depth(n+1);
	for(int i=0;i<k;i++){	
		int x;
		cin>>x;
		minDistance[x] = 0;
	}	

	for(int i=1;i<n;i++){
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	finalAns = 0;
	leafReachable = false;
	dfs(1, 0, graph, minDistance, depth);
	dfsAns(1, 0, graph, minDistance, depth);

	if(leafReachable){
		cout<<-1<<endl;
		return;
	}
	else{
		cout<<finalAns<<endl;
		return;
	}
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
