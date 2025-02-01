#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    vector<int> degree(n+1, 0);
    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] += 1;
        degree[v] += 1;
    }

    int maxDeg = *max_element(degree.begin(), degree.end());

    int ans = 0;
    int count = 0;
    for(int i=1;i<=n;i++){
        if(degree[i] == maxDeg){
            count++;
            for(auto neighbor:graph[i]){
                degree[neighbor] -= 1;
            }

            int nextMax = 0;
            for(int next=1;next<=n;next++){
                if(i==next){
                    continue;
                }
                nextMax = max(nextMax, degree[next]);
            }

            for(auto neighbor:graph[i]){
                degree[neighbor] += 1;
            }

            ans = max(ans, maxDeg + nextMax - 1);
        }
        if(count==2){
            break;
        }
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}