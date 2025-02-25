#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    unordered_map<long long, long long> countMap;
    long long maxNum = 0;
    for(long long i=0;i<n;i++){
        cin>>nums[i];
        maxNum = max(maxNum, nums[i]);
        countMap[nums[i]]++;
    }
    
    
    long long threshold = maxNum;
    long long ans = threshold + countMap[threshold];
    
    if(threshold>=2*n){
        for(int i=0;i<n;i++){
            ans = max(ans, nums[i] + countMap[nums[i]]);
        }
        cout<<ans<<endl;
        return;
    }
    
    for(long long gcdVal=1;gcdVal<=threshold;gcdVal++){
        long long sum = 0;
        for(long long multiple=gcdVal;multiple<=threshold;multiple+=gcdVal){
            if(countMap.count(multiple)){
                sum += countMap[multiple];
            }
        }
        ans = max(ans, sum + gcdVal);
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	long long t;
	cin>>t;
	while(t--){
	    solve();
	}
}
