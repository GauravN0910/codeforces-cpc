#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> sides(n);
    for(int i=0;i<n;i++){
        cin>>sides[i];
    }

    for(int i=0;i<n-1;i++){
        int x = sides[i];
        int y = sides[i+1];
        if(x>y){
            swap(x, y);
        }

        if(2*x > y){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}