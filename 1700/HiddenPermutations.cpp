#include<bits/stdc++.h>
using namespace std;

int ask(int i){
    cout<<"? "<<i+1<<endl;
    int x;
    cin>>x;
    return x-1;
}

void solve(){
    int n;
    cin>>n;
    vector<int> ans(n, -1);
    for(int i=0;i<n;i++){
        if(ans[i]==-1){
            int firstElem = ask(i);
            int nextElem = ask(i);
            vector<int> cycle;
            cycle.push_back(nextElem);
            while(nextElem!=firstElem){
                nextElem = ask(i);
                cycle.push_back(nextElem);
            }

            int sz = cycle.size();
            for(int idx=0;idx<sz;idx++){
                ans[cycle[idx]] = cycle[(idx + 1)%sz];
            }
        }
    }

    cout<<"! ";
    for(int i=0;i<n;i++){
        cout<<ans[i] + 1<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}