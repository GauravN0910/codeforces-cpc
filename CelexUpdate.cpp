#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x, y, X, Y;
        cin>>x>>y>>X>>Y;

        long long ans = (X-x)*(Y-y) + 1;
        cout<<ans<<endl;
    }
}