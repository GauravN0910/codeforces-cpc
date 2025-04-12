#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

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

void solve(vector<long long>& nums, vector<long long>& primeNums){
    for(auto n:nums){
        long long count = 0;
        for(auto num:primeNums){
            if(num>n){
                break;
            }
            count += n/num;
        }
        cout<<count<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    vector<long long> nums(t);
    long long maxNum = 0;
    for(long long i=0;i<t;i++){
        cin>>nums[i];
        maxNum = max(maxNum, nums[i]);
    }
    
    vector<bool> prime(maxNum + 10, 1);
    vector<long long> primeNums;
    SieveOfEratosthenes(maxNum, prime, primeNums);
    solve(nums, primeNums);
}