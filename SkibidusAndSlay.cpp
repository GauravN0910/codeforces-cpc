#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> values(n+1);
    for(long long i=1;i<=n;i++){
        cin>>values[i];
    }

    vector<map<long long, long long>> graph(n+1);
    vector<long long> ans(n+1);
    for(long long i=1;i<n;i++){
        long long u, v;
        cin>>u>>v;
        graph[u][values[v]]++;
        graph[v][values[u]]++;
        if(values[u] == values[v]){
            ans[values[u]] = 1;
        }

        if(graph[u][values[v]]>=2){
            ans[values[v]] = 1;
        }
        if(graph[v][values[u]]>=2){
            ans[values[u]] = 1;
        }
    }   

    for(long long i=1;i<=n;i++){
        cout<<ans[i];
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}