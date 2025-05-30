#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string s;
    cin>>s;
    int num = stoi(s);

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if((i+j)*(i+j) == num){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
    return;
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