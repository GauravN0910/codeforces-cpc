#include<bits/stdc++.h>
using namespace std;

long long check(vector<long long>& prefixSum, long long l, long long r, long long u){
    long long sum = prefixSum[r] - prefixSum[l-1];
    return (2*u - sum + 1)*sum/2;
}

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<long long> prefixSum(n+1);
    for(long long i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }

    long long q;
    cin>>q;
    while(q--){
        long long l, u;
        cin>>l>>u;
        long long low = l;
        long long high = n;
        while(low<high){
            long long mid = low + (high-low)/2;
            long long sumValid = check(prefixSum, l, mid, u);
            long long sumInvalid = check(prefixSum, l, mid+1, u);
            if(sumValid<sumInvalid){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        cout<<low<<" ";
    }
    cout<<endl;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}