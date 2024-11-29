#include<bits/stdc++.h>
using namespace std;

void solve(int n, int k){
    int oneCount = k-3;
    for(int i=0;i<oneCount;i++){
        cout<<1<<" ";
    }

    n = n-oneCount;
    if(n%2){
        cout<<n/2<<" "<<n/2<<" "<<1<<endl;
    }
    else{
        if(n%4==0){
            cout<<n/4<<" "<<n/4<<" "<<n/2<<endl;
        }
        else{
            cout<<(n/2 - 1)<<" "<<(n/2 - 1)<<" "<<2<<endl;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        solve(n, k);
        cout<<endl;
    }
}