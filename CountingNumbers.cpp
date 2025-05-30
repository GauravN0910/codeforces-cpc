#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long dp[20][11][2][2];

long long dfs(string& number, long long idx, long long prevNum, int leadingZero, long long tight){
	if(idx==number.size()){
		return 1;
	}

	if(dp[idx][prevNum+1][leadingZero][tight]!=-1){
		return dp[idx][prevNum+1][leadingZero][tight];
	}

	long long ans = 0;
	long long limit = (tight?number[idx]-'0':9);
	for(long long i=0;i<=limit;i++){
		if(!leadingZero && i==prevNum){
			continue;
		}
		ans += dfs(number, idx+1, i, (leadingZero & (i==0)), tight & (limit==i));
	}
	return dp[idx][prevNum+1][leadingZero][tight] = ans;
}

void solve(){
	long long l, r;
	cin>>l>>r;

	string stringL = to_string(l-1);
	string stringR = to_string(r);

	memset(dp, -1, sizeof(dp));
	long long right = dfs(stringR, 0, -1, 1, 1);
	long long left = 0;
	if(l!=0){
		memset(dp, -1, sizeof(dp));
		left = dfs(stringL, 0, -1, 1, 1);
	}

	long long ans = right - left;
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
