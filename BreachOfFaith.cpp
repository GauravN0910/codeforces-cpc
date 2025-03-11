#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin >> n;
    vector<long long> nums(2*n);
    for(long long i=0;i<2*n;i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    long long firstNum = nums[0];
    long long sum = 0;
    for(long long i=1;i<2*n;i++){
        if(i%2){
            sum += nums[i];
        }
        else{
            sum -= nums[i];
        }
    }
    long long requiredNum = sum + firstNum;
    cout << firstNum << " " << requiredNum << " ";
    for(long long i=1;i<2*n;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
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