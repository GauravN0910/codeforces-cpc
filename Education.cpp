#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
	long long n, c;
	cin>>n>>c;
	vector<long long> a(n);
	vector<long long> b(n);

	for(long long i=0;i<n;i++){
		cin>>a[i];
	}

	for(long long i=0;i<n-1;i++){
		cin>>b[i];
	}
	b[n-1] = 0;
	long long ans = 1e18;
	long long balance = 0;
	long long days = 0;
	for(long long i=0;i<n;i++){
		ans = min(ans, days + max(0LL, c - balance + a[i] - 1)/a[i]);
		long long daysToNext = max(0LL, b[i] - balance + a[i] - 1)/a[i];
		days += daysToNext + 1;
		balance += a[i] * daysToNext - b[i];
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
