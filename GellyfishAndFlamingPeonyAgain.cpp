#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int gcdPairs[5001][5001];
int dp[5001][5001];
void solve(){
	int n;
	cin>>n;

	int gcdVal = 0;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
		gcdVal = gcdPairs[nums[i]][gcdVal];
	}

	int gcdCount = 0;
	for(int i=0;i<n;i++){
		if(nums[i]==gcdVal){
			gcdCount++;
		}
		nums[i] /= gcdVal;
	}

	if(gcdCount){
		cout<<n-gcdCount<<endl;
		return;
	}

	for(int i=0;i<=n;i++){
		for(int gcd=0;gcd<=5000;gcd++){
			dp[i][gcd] = 1e8;
		}
	}

	for(int gcd=0;gcd<=5000;gcd++){
		dp[n][gcd] = (gcd==1?0:1e8);
	}

	for(int idx=n-1;idx>=0;idx--){
		for(int gcd=0;gcd<=5000;gcd++){
			if(gcd==1){
				dp[idx][gcd] = 0;
				continue;
			}

			int pick = 1 + dp[idx+1][gcdPairs[gcd][nums[idx]]];
			int notPick = dp[idx+1][gcd];
			dp[idx][gcd] = min(pick, notPick);
		}
	}

	int ans = dp[0][0] - 1 + (n - 1);
	cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

	for(int i=0;i<=5000;i++){
		gcdPairs[i][0] = gcdPairs[0][i] = i;
		gcdPairs[i][i] = i;
	}

	for(int i=1;i<=5000;i++){
		for(int j=1;j<i;j++){
			gcdPairs[i][j] = gcdPairs[j][i] = gcdPairs[j][i%j];
		}
	}

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
