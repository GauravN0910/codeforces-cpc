#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        long long ans = n;
        for(int b=2;b<=m;b++){
            long long y = n/b;
            if(y<b-1){
                break;
            }
            y -= (b-1);
            ans += ((y/b) + 1);
        }
        cout<<ans<<endl;
    }
}