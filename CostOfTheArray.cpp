#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    if(k<n){
        for(int i=1;i<=n-k+1;i++){
            if(nums[i]!=1){
                cout<<1<<endl;
                return;
            }
        }

        cout<<2<<endl;
        return;
    }
    else{
        int ans = 1;
        for(int i=1;i<n;i+=2){
            if(nums[i]==ans){
                ans++;
            }
            else{
                break;
            }
        }
        cout<<ans<<endl;
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