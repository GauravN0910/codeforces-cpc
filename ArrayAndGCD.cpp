#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long maxNum = 1e7;
long long maxN = 4e5;

void SieveOfEratosthenes(long long n, vector<bool>& prime, vector<long long>& primeNums){
    for (long long p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (long long i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for(long long i=2;i<=n;i++){
        if(prime[i]){
            primeNums.push_back(i);
        }
    }
}

void solve(vector<long long>& prefixSumPrimes){
    long long n;
    cin>>n;

    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    vector<long long> prefixSum(n+1);

    for(long long i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }

    long long maxInd = 0;
    for(long long ind=1;ind<=n;ind++){
        if(prefixSum[ind] >= prefixSumPrimes[ind]){
            maxInd = ind;
        }
        else{
            break;
        }
    }
    long long ans = n - maxInd;
    cout<<ans<<endl;    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    vector<long long> primeNums;
    vector<bool> prime(maxNum + 10, 1);
    SieveOfEratosthenes(maxNum, prime, primeNums);

    vector<long long> prefixSumPrimes(maxN + 1);
    for(long long i=1;i<=maxN;i++){
        prefixSumPrimes[i] = prefixSumPrimes[i-1] + primeNums[i-1];
    }

    long long t;
    cin>>t;
    while(t--){
        solve(prefixSumPrimes);
    }
}