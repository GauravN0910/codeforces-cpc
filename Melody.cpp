#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void dfs(map<long long, set<pair<long long, long long>>>& graph, vector<bool>& visited, vector<long long>& order, long long node){
	visited[node] = 1;
	while(graph[node].size()){
		pair<long long, long long> neighbor = *graph[node].rbegin();
		graph[node].erase(neighbor);
		long long nextNode = neighbor.first;
		long long idx = neighbor.second;
		graph[nextNode].erase({node, idx});
		dfs(graph, visited, order, nextNode);
	}
	order.push_back(node);
}

void solve(){
	long long n;
	cin>>n;

	map<long long, set<pair<long long, long long>>> graph;
	vector<long long> volume(n+1);
	vector<long long> pitch(n+1);
	set<long long> volSet;
	set<long long> pitchSet;
	for(long long i=1;i<=n;i++){
		cin>>volume[i]>>pitch[i];
		volSet.insert(volume[i]);
		pitchSet.insert(pitch[i]);
	}
	map<long long, long long> volMap;
	map<long long, long long> pitchMap;
	long long count = 1;
	for(auto x:volSet){
		volMap[x] = count++;
	}
	for(auto x:pitchSet){
		pitchMap[x] = count++;
	}

	for(long long i=1;i<=n;i++){
		volume[i] = volMap[volume[i]];
		pitch[i] = pitchMap[pitch[i]];
	}

	map<pair<long long, long long>, long long> edgeToIdxMap;

	for(long long i=1;i<=n;i++){
		graph[volume[i]].insert({pitch[i], i});
		graph[pitch[i]].insert({volume[i], i});
		edgeToIdxMap[{volume[i], pitch[i]}] = i;
		edgeToIdxMap[{pitch[i], volume[i]}] = i;
	}

	long long oddDeg = 0;
	long long startVertex = 1;
	for(auto x:graph){
		if(x.second.size()%2==1){
			startVertex = x.first;
			oddDeg++;
		}
	}

	if(oddDeg>=3){
		cout<<"NO"<<endl;
		return;
	}
	
	vector<long long> order;
	vector<bool> visited(count);
	dfs(graph, visited, order, startVertex);

	for(long long i=1;i<count;i++){
		if(!visited[i]){
			cout<<"NO"<<endl;
			return;
		}
	}

	cout<<"YES"<<endl;
	for(long long i=1;i<=n;i++){
		cout<<edgeToIdxMap[{order[i], order[i-1]}]<<" ";
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
