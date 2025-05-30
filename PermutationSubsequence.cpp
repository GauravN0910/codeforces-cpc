#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<int> LIS(vector<int>& nums, vector<int>& arr){
	int sz = nums.size();
	vector<int> ans;
	for(int i=0;i<sz;i++){
        auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
        arr[i] = it - ans.begin() + 1;
        if(it == ans.end()){
			ans.push_back(nums[i]);
		}
        else{
			*it = nums[i];
		}
	}
	return ans;
}

void solve(){
	int n, m;
	cin>>n>>m;

	vector<int> permA(n);
	vector<int> permB(m);

	for(int i=0;i<n;i++){
		cin>>permA[i];
	}

	for(int i=0;i<m;i++){
		cin>>permB[i];
	}

	if(m>n){
		swap(permA, permB);
		swap(n, m);
	}

	vector<int> newPermA;
	for(int i=0;i<n;i++){
		if(permA[i]<=m){
			newPermA.push_back(permA[i]);
		}
	}

	map<int, int> mapping;
	map<int, int> reverseMap;
	int count = 1;
	for(int i=0;i<m;i++){
		mapping[newPermA[i]] = count;
		reverseMap[count++] = newPermA[i];
	}

	for(int i=0;i<m;i++){
		permB[i] = mapping[permB[i]];
	}

	vector<int> arr(m);
	vector<int> LISResult = LIS(permB, arr);

	int LISSize = LISResult.size();
	vector<int> ans;
	cout<<LISSize<<endl;
	for(int i=m-1;i>=0;i--){
		if(arr[i]==LISSize){
			ans.push_back(reverseMap[permB[i]]);
			LISSize--;
		}
	}	

	for(auto x:arr){
		cout<<x<<" ";
	}
	cout<<endl;

	int sz = ans.size();
	reverse(ans.begin(), ans.end());
	for(int i=0;i<sz;i++){
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

    int t = 1;
    while(t--){
        solve();
    }
}
