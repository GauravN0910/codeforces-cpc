#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

void solve(){
	long long n;
	cin>>n;

	vector<long long> nums(n);
	for(long long i=0;i<n;i++){
		cin>>nums[i];
	}

	vector<long long> dpOne(n+5);
	vector<long long> dpTwo(n+5);
	dpOne[0] = 1;

	for(long long i=0;i<n;i++){
		long long x = nums[i];
		dpOne[x+1] = (dpOne[x+1] + dpOne[x+1] + dpOne[x])%mod;
		if(x>0){
			dpTwo[x-1] = (dpTwo[x-1] + dpTwo[x-1] + dpOne[x-1])%mod;
		}
		dpTwo[x+1] = (dpTwo[x+1] + dpTwo[x+1])%mod;
	}

	long long ans = 0;
	for(auto value:dpOne){
		ans = (ans + value)%mod;
	}
	for(auto value:dpTwo){
		ans = (ans + value)%mod;
	}
	cout<<(ans - 1 + mod)%mod<<endl;
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
