#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<vector<int>> edges;

struct DSU{
	vector<int> parent;
	vector<int> rank;
	int ans;
	void init(int n){
		parent.resize(n, 0);
		rank.resize(n, 0);
		iota(parent.begin(), parent.end(), 0);
		ans = 0;
	}

	int find(int x){
		if(parent[x]==x){
			return x;
		}
		return parent[x] = find(parent[x]);
	}

	void unify(int x, int y){
		int pX = find(x);
		int pY = find(y);

		if(pX == pY){
			return;
		}

		if(rank[pX]>rank[pY]){
			parent[pY] = pX;
		}
		else if(rank[pY]>rank[pX]){
			parent[pX] = pY;
		}
		else{
			parent[pY] = pX;
			rank[pX]++;
		}
		ans++;
	}
};

bool checkerFn(int mask, int n){
	DSU dsu;
	dsu.init(n+1);

	for(auto edge:edges){
		int u = edge[0];
		int v = edge[1];
		int w = edge[2];
		if((w & mask) == w){
			dsu.unify(u, v);
		}
	}
	return dsu.ans == n-1;
}

void solve(){
	int n, m;
	cin>>n>>m;
	edges.clear();
	
	for(int i=0;i<m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		edges.push_back({u, v, w});
	}

	int ans = 0;
	for(int i=0;i<=30;i++){
		ans = (ans | (1<<i));
	}
	
	for(int i=30;i>=0;i--){
		ans = (ans ^ (1<<i));
		bool x = checkerFn(ans, n);
		if(!x){
			ans = (ans ^ (1<<i));
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

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
