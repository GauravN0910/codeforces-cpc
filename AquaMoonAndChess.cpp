#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long factorial[100005];
long long invFactorial[100005];

long long binExp(long long n, long long pow){
    if(pow==0){
        return 1;
    }
    long long ans = binExp(n, pow/2);
    if(pow%2){
        return ((ans*ans)%mod * n)%mod;
    }
    return (ans*ans)%mod;
}

long long invMod(long long n){
    return (binExp(n, mod-2))%mod;
}

void precompute(){
    factorial[0] = 1;
    invFactorial[0] = 1;
    for(long long i=1;i<100005;i++){
        factorial[i] = (factorial[i-1] * i)%mod;
        invFactorial[i] = invMod(factorial[i])%mod;
    }
}

void solve(){
	long long n;
	cin>>n;
	string s;
	cin>>s;

	long long numGroups = 0;
	long long numZeroes = 0;	

	for(long long i=0;i<n;i++){
		if(s[i]=='0'){
			numZeroes++;
		}
		else if(i<n-1 && s[i]=='1' && s[i+1]=='1'){
			numGroups++;
			i++;
		}
	}

	long long ans = ((factorial[numGroups + numZeroes] * invFactorial[numGroups])%mod * invFactorial[numZeroes])%mod;
	cout<<ans<<endl;
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
