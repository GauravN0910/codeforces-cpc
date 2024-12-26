#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m, k;
    cin>>n>>m>>k;

    vector<int> lists(m);
    set<int> knownQs;

    for(int i=0;i<m;i++){
        cin>>lists[i];
    }

    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        knownQs.insert(x);
    }

    string ans = "";
    if(n-k>=2){
        for(int i=0;i<m;i++){
            ans += '0';
        }
        cout<<ans<<endl;
    }

    if(n==k){
        for(int i=0;i<m;i++){
            ans += '1';
        }
        cout<<ans<<endl;
    }

    if(n-k==1){
        for(int i=0;i<m;i++){
            if(knownQs.find(lists[i])==knownQs.end()){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }
        cout<<ans<<endl;
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