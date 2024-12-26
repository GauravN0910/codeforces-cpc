#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m, horizontalRequired;
    cin>>n>>m>>horizontalRequired;

    if(n%2==0 && m%2==0){
        if(horizontalRequired%2){
            cout<<"NO"<<endl;
            return;
        }
        else{
            cout<<"YES"<<endl;
            return;
        }
    }

    else if(n%2==0 && m%2){
        int minVertical = n/2;
        int verticalRequired = (m*n)/2 - horizontalRequired;
        if(verticalRequired>=minVertical && (verticalRequired - minVertical)%2==0){
            cout<<"YES"<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }

    else if(n%2 && m%2==0){
        int minHorizontal = m/2;
        if(horizontalRequired>=minHorizontal && (horizontalRequired - minHorizontal)%2==0){
            cout<<"YES"<<endl;
            return;
        }
        else{
            cout<<"NO"<<endl;
            return;
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