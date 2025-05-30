#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool checkerFn(vector<int>& nums, int mid){
	int n = nums.size();
	vector<int> count(n+1, 0);
	for(int i=0;i<n;i++){
		count[nums[i]]++;
	}

	priority_queue<pair<int, int>> pq;
	for(int i=1;i<=n;i++){
		if(count[i]){
			pq.push({count[i], i});
		}
	}
	
	vector<int> newNums(n, 0);
	for(int i=0;i<n;i++){
		if(i>=mid && count[newNums[i-mid]]){
			pq.push({count[newNums[i-mid]], newNums[i-mid]});
		}

		if(pq.empty()){
			return false;
		}
		pair<int, int> top = pq.top();
		newNums[i] = top.second;
		pq.pop();
		count[newNums[i]]--;
	}
	return true;
}

void solve(){
	int n;
	cin>>n;
	vector<int> nums(n);

	for(int i=0;i<n;i++){
		cin>>nums[i];
	}

	int low = 0;
	int high = n;
	int ans = 0;
	while(low<=high){
		int mid = low + (high - low)/2;
		if(checkerFn(nums, mid)){
			ans = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	cout<<max(ans-1, 0)<<endl;
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
