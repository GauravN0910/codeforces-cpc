#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);

    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    long long minIdx = min_element(nums.begin(), nums.end()) - nums.begin();

    long long gcdVal = 0;
    
    for(long long i=0;i<n;i++){
        if(i != minIdx && nums[i] % nums[minIdx] == 0){
            gcdVal = __gcd(gcdVal, nums[i]);
        }
    }

    if(gcdVal == nums[minIdx]){
        cout << "YES" << endl;
        return;
    }
    else{
        cout << "NO" << endl;
        return;
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
    while(t--){
        solve();
    }
}