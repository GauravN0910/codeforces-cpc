#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> ans(n+1, -1000);

    int x = 0;
    int sum = 0;
    for(int i=1;i<=n;i++){
        x += i;
        if(x>k){
            sum = x - k - 1;
            sum = sum*10 + 1;
            ans[i] = -1 * sum;
            break;
        }
        ans[i] = 10;
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}