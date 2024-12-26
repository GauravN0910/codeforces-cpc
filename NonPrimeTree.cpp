#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

bool prime[500010];

void SieveOfEratosthenes(long long n)
{
    for (long long p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (long long i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

void dfs(vector<vector<long long>>& graph, set<long long>& evenVals, set<long long>& oddVals, vector<long long>& assignedVals, long long node, long long parent){
    for(auto val:evenVals){
        if(parent==0 || prime[abs(assignedVals[parent] - val)]==0){
            assignedVals[node] = val;
            evenVals.erase(val);
            break;
        }
    }

    if(assignedVals[node]==1e9){
        for(auto val:oddVals){
            if(parent==0 || prime[abs(assignedVals[parent] - val)]==0){
                assignedVals[node] = val;
                oddVals.erase(val);
                break;
            }
        }
    }

    for(auto neighbor:graph[node]){
        if(neighbor==parent){
            continue;
        }
        dfs(graph, evenVals, oddVals, assignedVals, neighbor, node);
    }
}

void solve(){
    long long n;
    cin>>n;
    vector<vector<long long>> graph(n+1);
    for(long long i=0;i<n-1;i++){
        long long u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }   

    vector<long long> assignedVals(n+1, 1e9);
    set<long long> evenVals;
    for(long long val=2;val<=2*n;val+=2){
        evenVals.insert(val);
    }

    set<long long> oddVals;
    for(long long val=1;val<=2*n;val+=2){
        oddVals.insert(val);
    }

    dfs(graph, evenVals, oddVals, assignedVals, 1, 0);
    for(long long i=1;i<=n;i++){
        cout<<assignedVals[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(long long i=2;i<500010;i++){
        prime[i] = 1;
    }
    SieveOfEratosthenes(500005);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}