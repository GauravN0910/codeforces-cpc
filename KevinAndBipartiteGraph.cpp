#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;

    int maxM = 2*n - 1;
    if(m>maxM){
        cout<<"NO"<<endl;
        return;
    }  
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<2*n;i++){
            for(int j=0;j<m;j++){
                int x = ((i+j)%(2*n))/2 + 1;
                cout<<x<<" ";
            }
            cout<<endl;
        }
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