#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<-1<<endl;
        return;
    }

    else{
        for(int i=1;i<=n;i++){
            cout<<(2*i)%n + 1<<" ";
        }
        cout<<endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}