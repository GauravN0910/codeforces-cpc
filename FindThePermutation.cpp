#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

string graph[10000];

static bool cmp(int x, int y){
    if(x<y){
        return graph[x][y] == '1';
    }
    else{
        return graph[x][y] == '0';
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>graph[i];
    }

    vector<int> ans(n);

    for(int i=0;i<n;i++){
        ans[i] = i;
    }

    sort(ans.begin(), ans.end(), cmp);

    for(int i=0;i<n;i++){
        cout<<ans[i] + 1<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
