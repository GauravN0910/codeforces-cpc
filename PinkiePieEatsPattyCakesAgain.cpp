#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;

	vector<int> nums(n);
	vector<int> count(n+1);
	for(int i=0;i<n;i++){
		cin>>nums[i];
		count[nums[i]]++;
	}

	int maxCount = *max_element(count.begin(), count.end());
	int numsWithMaxCount = 0;
	for(int i=1;i<=n;i++){
		if(count[i]==maxCount){
			numsWithMaxCount++;
		}
	}

	int remainingNums = n - numsWithMaxCount*maxCount;
	int numGaps = maxCount - 1;
	int ans = numsWithMaxCount - 1 + remainingNums/numGaps;
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
