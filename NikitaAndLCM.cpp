#include<bits/stdc++.h>
using namespace std;

long long lcm(long long x, long long y){
    return ((x*y)/__gcd(x, y));
}

void solve(){
    long long n;
    long long LCM = 1;
    long long ans = 0;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
        if(LCM<=1e9){
            LCM = lcm(LCM, nums[i]);
        }
    }
    sort(nums.begin(), nums.end());
    if(LCM > nums[n-1]) {cout<<n<<endl; return;}

    vector<long long> factors;
    for(long long i=1;i*i<=LCM;i++){
        if((LCM%i)==0){
            factors.push_back(i);
            factors.push_back(LCM/i);
        }
    }
    
    for(auto factor:factors){
        auto x = lower_bound(nums.begin(), nums.end(), factor);
        if(x==nums.end() || *x != factor){
            long long temp = 0, lcmTemp = 1;
            for(auto num:nums){
                if(factor%num==0){
                    temp++;
                    lcmTemp = lcm(lcmTemp, num);
                }
            }
            if(factor==lcmTemp){
                ans = max(ans, temp);
            }
        }
    }
    cout<<ans<<endl;    

}

int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}