#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;

    vector<int> graph(n+1);
    vector<int> inDeg(n+1);
    for(int i=1;i<=n;i++){
        cin>>graph[i];
        inDeg[graph[i]]++;
    }

    vector<int> plushieCount(n+1, 1);

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
    }

    int ans = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans = max(ans, plushieCount[node]);
        int neighbor = graph[node];
        plushieCount[neighbor] += plushieCount[node];
        inDeg[neighbor]--;
        if(inDeg[neighbor]==0){
            q.push(neighbor);
        }
    }   
    cout<<ans+2<<endl; /* +2 is time for any cycle to become stable */
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}