#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 2e5 + 10;

void solve(){
	int n;
	cin>>n;

	vector<int> nums(n);
	map<int, int> count;
	for(int i=0;i<n;i++){
		cin>>nums[i];
		count[nums[i]]++;
	}

	vector<int> dp(maxN, 0);
	for(int i=1;i<maxN;i++){
		dp[i] += count[i];
		for(int j=2*i;j<maxN;j+=i){
			dp[j] = max(dp[j], dp[i]);
		}
	}
	int maxElem = *max_element(dp.begin(), dp.end());
	int ans = n - maxElem;
	cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
