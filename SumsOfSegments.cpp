#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n+1, 0);
    for(long long i=1;i<=n;i++){
        cin>>nums[i];
    }

    vector<long long> prefixSum(n+1);
    long long prefixPrefixSum = 0;
    for(long long i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1] + nums[i];
        prefixPrefixSum += prefixSum[i];
    }

    vector<long long> prefixSumOfPrefixSum(n+1);
    for(long long i=1;i<=n;i++){
        prefixSumOfPrefixSum[i] = prefixSumOfPrefixSum[i-1] + prefixSum[i];
    }

    vector<long long> setPrefixSum(n+1);
    setPrefixSum[1] = prefixPrefixSum;
    for(long long i=2;i<=n;i++){
        setPrefixSum[i] = setPrefixSum[i-1] - (nums[i-1]*(n-i+2));
    }

    vector<long long> prefixSetPrefixSum(n+1);
    for(long long i=1;i<=n;i++){
        prefixSetPrefixSum[i] = prefixSetPrefixSum[i-1] + setPrefixSum[i];
    }


    vector<long long> setBegin;
    setBegin.push_back(0);
    setBegin.push_back(1);
    long long prevBegin = 1;
    long long increase = n;
    while(increase>=1){
        long long newBegin = prevBegin + increase;
        setBegin.push_back(newBegin);
        prevBegin = newBegin;
        increase--;
    }

    long long q;
    cin>>q;

    while(q--){
        long long l, r;
        cin>>l>>r;

        long long leftIdx = upper_bound(setBegin.begin(), setBegin.end(), l) - setBegin.begin() - 1;
        long long rightIdx = upper_bound(setBegin.begin(), setBegin.end(), r) - setBegin.begin() - 1;

        long long ans = prefixSetPrefixSum[rightIdx] - prefixSetPrefixSum[leftIdx-1];

        long long rightEnd = setBegin[rightIdx+1] - 1;
        long long rightDiff = rightEnd - r;

        long long leftDiff = l - setBegin[leftIdx];

        long long rightRemove = prefixSumOfPrefixSum[n] - prefixSumOfPrefixSum[n-rightDiff] - (prefixSum[rightIdx-1] * rightDiff);
        long long leftRemove = prefixSumOfPrefixSum[leftDiff + leftIdx - 1] - prefixSumOfPrefixSum[leftIdx - 1] - (prefixSum[leftIdx-1] * leftDiff);

        ans = (ans - leftRemove - rightRemove);
        cout<<ans<<endl;
    }
}

int main(){
    long long t = 1;
    while(t--){
        solve();
    }
}