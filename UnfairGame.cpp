#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;

        int ans = 0;
        ans += (a/2 + b/2 + c/2 + d/2);
        if(a%2 && b%2 && c%2){
            ans++;
        }
        cout<<ans<<endl;
    }
}