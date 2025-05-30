#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void dfs(int node, vector<set<int>>& graph, vector<int>& order){
	while(graph[node].size()){
		int neighbor = *graph[node].rbegin();
		graph[node].erase(neighbor);
		dfs(neighbor, graph, order);
	}
	order.push_back(node);
}

void solve(){
	int n, m;
	cin>>n>>m;

	vector<set<int>> graph(n+1);
	vector<int> degree(n+1);
	for(int i=0;i<m;i++){
		int u, v;
		cin>>u>>v;
		graph[u].insert(v);
		degree[u]++;
		degree[v]--;
	}

	if(degree[1]!=1){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	
	int startNode = 1;
	int oddDegCount = 0;
	for(int i=1;i<=n;i++){
		if(abs(degree[i])%2){
			oddDegCount++;
			if(degree[i]==1 && i!=1){
				cout<<"IMPOSSIBLE"<<endl;
				return;
			}
		}
	}

	if(oddDegCount!=2){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}

	vector<int> order;
	dfs(startNode, graph, order);

	reverse(order.begin(), order.end());
	if(order.size()!=m+1 || order.back()!=n){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	for(auto x:order){
		cout<<x<<" ";
	}
	cout<<endl;
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
