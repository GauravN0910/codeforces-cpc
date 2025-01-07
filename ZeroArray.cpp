#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;

    vector<long long> nums(n);
    long long sum = 0;
    long long maxElement = 0;
    for(long long i=0;i<n;i++){
        cin>>nums[i];
        sum += nums[i];
        maxElement = max(maxElement, nums[i]);
    }
 
    if(sum%2==0 && sum>=2*maxElement){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t = 1;
    while(t--){
        solve();
    }
}