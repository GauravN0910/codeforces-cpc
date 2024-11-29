#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, x;
    cin>>n>>x;

    vector<int> degree(n+1);
    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
    }

    int specialDegree = degree[x];
    cout<<((specialDegree>1 && n%2)?"Ashish":"Ayush")<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}