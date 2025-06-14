#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, k;
    cin>>n>>k;

    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    long long ans = 0;
    map<long long, long long> count;
    for(long long i=0;i<n;i++){
        for(long long bit=0;bit<=61;bit++){
            if(bit<=30){
                if(!(nums[i] & (1<<bit))){
                    count[bit]++;
                }
            }
            else{
                count[bit]++;
            }
        }
        ans += __builtin_popcount(nums[i]);
    }

    for(auto [exp, count]:count){
        long long numOps = pow(2, exp);
        long long numTimes = min(count, k/numOps);
        ans += numTimes;
        k -= numTimes * numOps;
    }

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
