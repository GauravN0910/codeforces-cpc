#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void ceilDivisions(int n, vector<pair<int, int>>& ans){
    if(n<=2){
        return;
    }
    int limit = max(2, (int)sqrt(n)+1);

    for(int i=limit+1;i<n;i++){
        ans.push_back({i, n});
    }
    ans.push_back({n, limit});
    ans.push_back({n, limit});
    ceilDivisions(limit, ans);  
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int, int>> ans;
    ceilDivisions(n, ans);
    cout<<ans.size()<<endl;
    for(auto [x, y]:ans){
        cout<<x<<" "<<y<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}