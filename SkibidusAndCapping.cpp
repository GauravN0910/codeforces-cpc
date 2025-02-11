#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

bool prime[200001];

void precompute(){
    for(long long i=2;i<=200000;i++){
        prime[i] = true;
    }
    for (long long p = 2; p * p <= 200000; p++) {
        if (prime[p] == true) {
            for (long long i = p * p; i <= 200000; i += p)
                prime[i] = false;
        }
    }
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    map<long long, long long> numMap;
    for(long long i=0;i<n;i++){
        cin>>nums[i];
        numMap[nums[i]]++;
    }

    map<long long, long long> primeMap;
    map<long long, long long> semiPrimeMap;

    long long totalPrimes = 0;
    for(long long i=0;i<n;i++){
        if(prime[nums[i]]){
            totalPrimes++;
            primeMap[nums[i]]++;
        }
    }

    long long ans = 0;
    for(long long i=0;i<n;i++){
        for(long long j=2;j*j<=nums[i];j++){
            if(nums[i]%j==0){
                if(prime[j] && prime[nums[i]/j]){
                    semiPrimeMap[nums[i]]++;
                    if(numMap.count(j)){
                        ans += numMap[j];
                    }
                    if(nums[i]/j != j && numMap.count(nums[i]/j)){
                        ans += numMap[nums[i]/j];
                    }
                }
            }
        }
    }       

    for(auto x:semiPrimeMap){
        ans += ((x.second)*(x.second+1))/2;
    }

    for(auto x:primeMap){
        long long extra = (totalPrimes - x.second)*x.second;
        ans += extra;
        totalPrimes -= x.second;
    }

    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    precompute();
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}