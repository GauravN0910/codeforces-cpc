#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
	long long n, m;
	cin>>n>>m;

	vector<long long> nums(n);
	long long sum = 0;
	vector<long long> prefixSum;
	vector<long long> index;
	for(long long i=0;i<n;i++){
		cin>>nums[i];
		sum += nums[i];
		if(prefixSum.empty() || sum>prefixSum.back()){
			prefixSum.push_back(sum);
			index.push_back(i);
		}
	}
	long long maxPrefix = prefixSum.back();

	while(m--){
		long long val;
		cin>>val;
		if(sum<=0 && maxPrefix<val){
			cout<<-1<<" ";
			continue;
		}

		long long numRotations = 0;
		if(maxPrefix<val){
			numRotations = (val - maxPrefix + sum - 1)/sum;
			val -= numRotations*sum;
		}
		
		long long idx = lower_bound(prefixSum.begin(), prefixSum.end(), val) - prefixSum.begin();
		long long ans = n*numRotations + index[idx];
		cout<<ans<<" ";
	}
	cout<<endl;
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
