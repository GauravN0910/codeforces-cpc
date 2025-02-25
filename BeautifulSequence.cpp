#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    long long ans = 0;
    long long oneCount = 0;
    long long sum = 0;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            oneCount++;
            sum++;
        }
        else if(nums[i]==2){
            sum = (sum*2)%mod;
        }
        else{
            ans = (ans + sum - oneCount + mod)%mod;
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}