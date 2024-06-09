#include <bits/stdc++.h>
using namespace std;

int dp[10][2][2];
int dfs(string& s, int idx, int tight, int flag){
	if(idx==s.size()){
		return flag;
	}

	if(dp[idx][tight][flag]!=-1){
		return dp[idx][tight][flag];
	}

	int ans = 0;
	int limit = (tight?s[idx]-'0':9);
	for(int i=0;i<=limit;i++){
		int updateFlag = (flag | (i==3));
		ans += dfs(s, idx+1, tight & (limit==i), updateFlag);
	}
	return dp[idx][tight][flag] = ans;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		string s = to_string(n);
		memset(dp, -1, sizeof(dp));
		int ans = dfs(s, 0, 1, 0);
		cout<<n-ans<<endl;
	}
}