#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool checkerFn(vector<int>& nums, vector<int>& operations, int mid){
	int count = 0;
	for(auto x:nums){
		if(x<=mid){
			count++;
		}
	}
	for(auto x:operations){
		if(x>0 && x<=mid){
			count++;
		}
		if(x<0 && abs(x)<=count){
			count--;
		}
	}
	return count>0;
}

void solve(){
	int n, q;
	cin>>n>>q;
	vector<int> nums(n);
	vector<int> operations(q);

	for(int i=0;i<n;i++){
		cin>>nums[i];
	}

	for(int i=0;i<q;i++){
		cin>>operations[i];
	}

	int low = 1;
	int high = n;
	int ans = 0;
	while(low<=high){
		int mid = low + (high - low)/2;
		if(checkerFn(nums, operations, mid)){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
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

    int t = 1;
    while(t--){
        solve();
    }
}
