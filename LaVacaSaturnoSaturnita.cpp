#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

vector<vector<long long>> factorsNums(100001);

void precompute(){
    for(int i=2;i<=100000;i++){
        for(int j=i;j<=100000;j+=i){
            factorsNums[j].push_back(i);
        }
    }
}

vector<long long> factorise(long long k){
	vector<long long> factors;
	for(long long i=1;i*i<=k;i++){
		if(k%i==0){
			factors.push_back(i);
			factors.push_back(k/i);
		}
	}
	return factors;
}

void solve(){
	long long n, q;
	cin>>n>>q;

	map<long long, vector<long long>> map;

	vector<long long> nums(n+1);
	for(long long i=1;i<=n;i++){
		cin>>nums[i];
		map[nums[i]].push_back(i);
	}

	while(q--){
		long long k, l, r;
		cin>>k>>l>>r;

		long long ans = 0;
		long long prevIdx = l;

		while(true){
			vector<long long> factors = factorsNums[k];
			
			long long minIdx = 1e9;
			for(auto factor:factors){
				auto idx = lower_bound(map[factor].begin(), map[factor].end(), prevIdx);
				if(idx != map[factor].end()){
					minIdx = min(minIdx, *idx);
				}
			}

			if(minIdx>r){
				break;
			}

			ans += k * (minIdx - prevIdx);
			while(k%nums[minIdx] == 0){
				k /= nums[minIdx];
			}
			prevIdx = minIdx;
		}

		ans += k * (r - prevIdx + 1);
		cout<<ans<<endl;
	}
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    precompute();
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}
