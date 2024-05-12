#include<bits/stdc++.h>
using namespace std;

int parent[1000010];
int ans[1000010];
int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=m+n;i++){
        parent[i] = i;
    }
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        while(x--){
            int y;
            cin>>y;
            parent[find(y)] = find(n+i);
        }
    }

    for(int i=1;i<=n;i++){
        parent[i] = find(i);
    }

    for(int i=1;i<=n;i++){
        ans[parent[i]]++;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[parent[i]]<<" ";
    }
    cout<<endl;
}