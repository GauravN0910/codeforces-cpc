#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
	long long n, x;
	cin>>n>>x;

	vector<long long> nums(n+1);
	for(long long i=1;i<=n;i++){
		cin>>nums[i];
	}

	for(long long i=1;i<=n;i++){
		nums.push_back(nums[i]);
	}

	vector<long long> prefixSum(2*n + 1);
	vector<long long> numHugsPrefix(2*n + 1);
	for(long long i=1;i<=2*n;i++){
		prefixSum[i] = prefixSum[i-1] + nums[i];
		numHugsPrefix[i] = numHugsPrefix[i-1] + (nums[i]*(nums[i]+1))/2;
	}

	long long ans = 0;
	for(long long i=1;i<=n;i++){
		long long endIdx = lower_bound(prefixSum.begin()+1, prefixSum.end(), prefixSum[i - 1] + x) - prefixSum.begin();
		if(endIdx==i){     
			long long tempAns = (nums[i]*(nums[i]+1))/2;
			long long remaining = nums[i] - x;
			tempAns -= (remaining*(remaining+1))/2;
			ans = max(ans, tempAns);
		}
		else{
			long long tempAns = numHugsPrefix[endIdx - 1] - numHugsPrefix[i - 1];
			long long extra = x - (prefixSum[endIdx - 1] - prefixSum[i - 1]);
			tempAns += (extra*(extra+1))/2;
			
			long long remaining = min(nums[i] - 1, nums[endIdx] - extra);
			tempAns += remaining * extra; 
			/*The additional hugs from last month are more 
			than removed hugs from first month by extra
			Assume extra = 3, next additional number of hugs from 
			last month will be 4 and removed number of hugs will be 1
			(add 4, remove 1), (add5, remove 2) and so on*/
			ans = max(ans, tempAns);
		}

	}
	cout<<ans<<endl;
}
	
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t = 1;
    while(t--){
        solve();
    }
}
