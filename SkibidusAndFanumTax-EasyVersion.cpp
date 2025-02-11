#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    sort(b.begin(), b.end());

    a[0] = min(a[0], b[0] - a[0]);
    for(int i=1;i<n;i++){
        int numToSearch = a[i] + a[i-1];
        int index = lower_bound(b.begin(), b.end(), numToSearch) - b.begin();
        
        if(a[i]>=a[i-1]){
            if(index != m){
                a[i] = min(a[i], b[index] - a[i]);
            }
        }
        else{
            if(index == m){
                cout<<"NO"<<endl;
                return;
            }
            else{
                a[i] = b[index] - a[i];
            }
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}