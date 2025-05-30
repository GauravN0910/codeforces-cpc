#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;
	vector<int> nums(n+1);
	vector<int> visited(n+1);
	
	int containsRep = false;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
		if(visited[nums[i]]){
			containsRep = true;
		}
		visited[nums[i]] = 1;
	}

	if(containsRep){
		cout<<"YES"<<endl;
		return;
	}
	/*
	If it contains no repeated elements, then the given array is a permutation
	For the given permutation to be a valid, it must be an even permutation (even number of inversions)
	Why? A three-cycle swap is equivalent to 2 two-cycle swaps => abc -> bca can be written as abc -> bac -> bca
	*/
	for(int i=1;i<n;i++){
		if(nums[i]!=i && nums[i]!=n){
			swap(nums[i], nums[nums[i]]);
			swap(nums[i], nums[n]);
			i--;
		}
	}

	if(nums[n]==n){
		cout<<"YES"<<endl;
		return;
	}
	else{
		cout<<"NO"<<endl;
		return;
	}
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
