#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, a, b, c;
    cin>>n>>a>>b>>c;

    int sum = a + b + c;
    int ans = (n/sum)*3;

    int sumAB = a + b;
    n = n%sum;

    if(n==0){
        cout<<ans<<endl;
        return;
    }
    else if(n>sumAB){
        ans += 3;
        cout<<ans<<endl;
        return;
    }
    else if(n>a){
        ans += 2;
        cout<<ans<<endl;
        return;
    }
    else{
        ans += 1;
        cout<<ans<<endl;
        return;
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