#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	vector<int> ans(n, 0);

	int curMax = nums[0];
	for(int i=1;i<n;i++){
		if(nums[i]>curMax){
			if(nums[i]<2*curMax){
				ans[i] = nums[i];
			}
			else{
				int tempAns = 0;
				for(int idx=0;idx<i;idx++){
					tempAns = max(tempAns, nums[idx] + nums[i]%nums[idx]);
				}
				ans[i] = max(tempAns, ans[i-1]);
			}
		}
		else if(nums[i]==curMax){
			ans[i] = ans[i-1];
		}
		else{
			ans[i] = max(ans[i-1], nums[i]+ curMax%nums[i]);
		}
		curMax = max(curMax, nums[i]);
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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
