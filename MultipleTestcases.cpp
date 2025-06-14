#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n, k;
	cin>>n>>k;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}

	vector<int> maxNumArrays(k+1);
	for(int i=1;i<=k;i++){
		cin>>maxNumArrays[i];
	}
	
	sort(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	int ans = 0;
	int greaterElems = 0;
	for(int i=k;i>=1;i--){
		while(greaterElems<n && nums[greaterElems]==i){
			greaterElems++;
		}
		ans = max(ans, (greaterElems + maxNumArrays[i] - 1)/maxNumArrays[i]);
	}

	cout<<ans<<endl;
	vector<vector<int>> finalAns(ans);
	for(int i=0;i<n;i++){
		finalAns[i%ans].push_back(nums[i]);
	}

	for(int i=0;i<ans;i++){
		cout<<finalAns[i].size()<<" ";
		for(auto x:finalAns[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

	int t = 1;
    while(t--){
        solve();
    }
}
