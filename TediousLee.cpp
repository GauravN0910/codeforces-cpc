#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

const long long maxN = 2e6 + 10;

long long dp[maxN];

void precompute(){
	dp[1] = 0;
	dp[2] = 0;
	
	for(long long i=3;i<=2e6;i++){
		dp[i] = (2*dp[i-2] + dp[i-1])%mod;
		if(i%3==0){
			dp[i] = (dp[i] + 4)%mod;
		} 
	}
}

void solve(){
	long long n;
	cin>>n;
	cout<<dp[n]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
	precompute();
    while(t--){
        solve();
    }
}
