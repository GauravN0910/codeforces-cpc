#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    if(n%2){
        cout<<"Bob"<<endl;
    }
    else{
        if(!(n&(n-1))){
            int x = 0;
            while(n){
                n /= 2;
                x++;
            }
            if(x%2){
                cout<<"Alice"<<endl;
            }
            else{
                cout<<"Bob"<<endl;
            }
        }
        else{
            cout<<"Alice"<<endl;
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