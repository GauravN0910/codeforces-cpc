#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<int> ask(int node, int n){
    cout<<"? "<<node<<endl;
    vector<int> distance(n+1);
    for(int i=1;i<=n;i++){
        cin>>distance[i];
    }
    return distance;
}

void solve(){
    int n;
    cin>>n;

    vector<int> distance = ask(1, n);
    vector<pair<int, int>> ans;
    vector<int> nodes[2];


    for(int i=1;i<=n;i++){
        if(distance[i]==1 && i!=1){
            ans.push_back({1, i});
        }
        if(i>1){
            nodes[distance[i]%2].push_back(i);
        }   
    }

    vector<int> nextLevel;
    if(nodes[0].size()<nodes[1].size()){
        nextLevel = nodes[0];
    }
    else{
        nextLevel = nodes[1];
    }

    for(auto node:nextLevel){
        vector<int> distances = ask(node, n);
        for(int i=1;i<=n;i++){
            if(distances[i]==1 && i!=1){
                ans.push_back({node, i});
            }
        }
    }

    cout<<"!"<<endl;
    for(auto [x, y]:ans){
        cout<<x<<" "<<y<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}