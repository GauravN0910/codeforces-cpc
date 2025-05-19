#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool checkerFn(vector<int>& nums, int mid, int k){
	int n = nums.size();

    int numArrays = 0;
    
    set<int> numSet;
    for(int i=0;i<n;i++){
        if(nums[i]<mid){
            numSet.insert(nums[i]);
        }
        if(numSet.size() == mid){
            numArrays++;
            numSet.clear();
        }
    }
    return numArrays>=k;
}

void solve(){
    int n, k;
	cin>>n>>k;
	
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}

	int low = 0;
	int high = n/k;
	int ans = 0;

	while(low<=high){
		int mid = low + (high - low)/2;
		if(checkerFn(nums, mid, k)){
			ans = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}

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
