#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    multiset<int> mSetA;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mSetA.insert(a[i]);
    }

    vector<int> b(n);
    priority_queue<int> pqB;
    for(int i=0;i<m;i++){
        cin>>b[i];
        pqB.push(b[i]);
    }

    int flag = true;
    while(!pqB.empty() && flag){
        int target = pqB.top();
        pqB.pop();
        if(mSetA.find(target)!=mSetA.end()){
            mSetA.erase(mSetA.find(target));
        }
        else{
            if(target%2==0){
                int x = target/2;
                pqB.push(x);
                pqB.push(x);
            }
            else{
                int x = target/2;
                pqB.push(x);
                pqB.push(x+1);
            }
        }
        if(pqB.size()>mSetA.size()){
            flag = false;
        }   
    }

    if(!mSetA.empty()){
        flag = false;
    }

    if(flag){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
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