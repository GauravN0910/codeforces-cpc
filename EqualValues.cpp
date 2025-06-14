#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
	long long n;
	cin>>n;
	vector<long long> nums(n+1);
	for(long long i=1;i<=n;i++){
		cin>>nums[i];
	}

	long long ans = 1e18;
	long long i = 1;
	while(i<=n){
		long long j = i;
		while(j<=n && nums[j]==nums[i]){
			j++;
		}
		ans = min(ans, nums[i] * (n - (j - i)));
		i = j;
	}
	cout<<ans<<endl;
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
