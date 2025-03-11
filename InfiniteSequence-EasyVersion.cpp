#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long dfs(vector<long long>& prefixXor, vector<long long>& nums, long long m, long long n, long long xorVal){
    if(m<=n){
        return nums[m];
    }
    m = m/2;
    if(m<=n){
        return prefixXor[m];
    }

    if(m%2==1){
        return xorVal;
    }
    else{
        return xorVal ^ dfs(prefixXor, nums, m, n, xorVal);
    }
}

void solve(){
    long long n, l, r;
    cin>>n>>l>>r;
    vector<long long> nums(n+2);

    long long xorVal = 0;
    for(long long i=1;i<=n;i++){
        cin>>nums[i];
        xorVal ^= nums[i];
    }

    vector<long long> prefixXor(n+2);
    for(long long i=1;i<=n;i++){
        prefixXor[i] = prefixXor[i-1] ^ nums[i];
    }

    if(n%2==0){
        n++;
        nums[n] = prefixXor[n/2];
        prefixXor[n] = prefixXor[n-1] ^ nums[n];
        xorVal ^= nums[n];
    }

    long long ans = dfs(prefixXor, nums, l, n, xorVal);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}