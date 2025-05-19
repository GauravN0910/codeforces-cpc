#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int q;
    cin>>q;

    int MAXN = 5e5 + 10;
    vector<int> nums;
    vector<int> parent(MAXN);
    iota(parent.begin(), parent.end(), 0);

    vector<vector<int>> queries(q+1);

    for(int i=1;i<=q;i++){
        int type, x;
        cin>>type>>x;
        queries[i].push_back(type);
        queries[i].push_back(x);
        if(type==2){
            int y;
            cin>>y;
            queries[i].push_back(y);
        }
    }
    
    vector<int> ans;

    for(int idx=q;idx>=1;idx--){

        if(queries[idx][0] == 1){
            ans.push_back(parent[queries[idx][1]]);
        }
        else if(queries[idx][0] == 2){
            int x = queries[idx][1];
            int y = queries[idx][2];
            
            parent[x] = parent[y];
        }
    }

    reverse(ans.begin(), ans.end());
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t = 1;
    while(t--){
        solve();
    }
}