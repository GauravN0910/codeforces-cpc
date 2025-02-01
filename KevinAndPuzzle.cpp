#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

void solve(){
    long long n;
    cin >> n;
    vector<long long> nums(n);
    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    map<long long, long long> prevHonest, prevLiar;
    prevHonest[0] = 1;

    for (long long i = 0; i < n; ++i) {
        long long liarsLeft = nums[i];
        long long ways = (prevHonest[liarsLeft] + prevLiar[liarsLeft]) % mod;
        map<long long, long long> currHonest, currLiar;

        if (ways > 0) {
            currHonest[liarsLeft] = ways;
        }

        for (auto& elem : prevHonest) {
            long long left = elem.first;
            long long count = elem.second;
            currLiar[left + 1] = (currLiar[left + 1] + count) % mod;
        }

        prevHonest = currHonest;
        prevLiar = currLiar;
    }

    long long ans = 0;
    for (auto& elem : prevHonest) {
        ans = (ans + elem.second) % mod;
    }
    
    for (auto& elem : prevLiar) {
        ans = (ans + elem.second) % mod;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}