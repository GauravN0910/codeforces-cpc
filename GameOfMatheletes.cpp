#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;
    multiset<int, greater<int>> mSet;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(mSet.find(k-x)!=mSet.end()){
            mSet.erase(mSet.find(k-x));
            ans++;
        }
        else{
            mSet.insert(x);
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