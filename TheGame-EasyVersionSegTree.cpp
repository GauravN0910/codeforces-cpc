#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct SegTree{
    int size;
    vector<long long> sums;

    void init(int n){
        size = 1;
        while(size<n){
            size = size*2;
        }
        sums.assign(2*size, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            sums[x] = v;
            return;
        }
        int mid = (lx + rx)/2;
        if(i<mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else{
            set(i, v, 2*x+2, mid, rx);
        }
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void set(int i, int v){
        return set(i, v, 0, 0, size);
    }

    long long rangeQuery(int l, int r, int x, int lx, int rx){
        if(lx>=r || l>=rx){
            return 0;
        }
        if(lx>=l && rx<=r){
            return sums[x];
        }

        int mid = (lx+rx)/2;
        long long left = rangeQuery(l, r, 2*x+1, lx, mid);
        long long right = rangeQuery(l, r, 2*x+2, mid, rx);
        return left+right;
    }

    long long rangeQuery(int l, int r){
        return rangeQuery(l, r, 0, 0, size);
    }

};

void dfs(vector<vector<int>>& graph, vector<int>& dfsOrder, vector<int>& subTreeSize, int node, int parent){
    dfsOrder.push_back(node);
    subTreeSize[node] = 1;
    for(auto neighbor:graph[node]){
        if(neighbor!=parent){
            dfs(graph, dfsOrder, subTreeSize, neighbor, node);
            subTreeSize[node] += subTreeSize[neighbor];
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> values(n+1);
    vector<vector<int>> graph(n+1);
    vector<vector<int>> valToNode(n+1);
    for(int i=1;i<=n;i++){
        cin>>values[i];
        valToNode[values[i]].push_back(i);
    }

    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dfsOrder;
    map<int, int> revMap;
    vector<int> subTreeSize(n+1);
    dfs(graph, dfsOrder, subTreeSize, 1, 0);
    for(int i=0;i<n;i++){
        revMap[dfsOrder[i]] = i;
    }

    SegTree segTree;
    segTree.init(n);

    for(int val=n;val>=1;val--){
        for(auto node:valToNode[val]){
            int left = revMap[node];
            int right = revMap[node] + subTreeSize[node];


            int insideRange = segTree.rangeQuery(left, right);
            int outsideRange = segTree.rangeQuery(0, n);

            if(insideRange!=outsideRange){
                cout<<node<<endl;
                return;
            }
        }

        for(auto node:valToNode[val]){
            segTree.set(revMap[node], 1);
        }
    }
    cout<<0<<endl;

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