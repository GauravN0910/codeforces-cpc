#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;

	vector<int> nums(n);

	int zeroCount = 0;

	for(int i=0;i<n;i++){
		cin>>nums[i];
		if(nums[i]==0){
			zeroCount++;
		}
	}

	for(int i=1;i<n;i++){
		if(nums[i]==0 && nums[i-1]==0){
			cout<<"YES"<<endl;
			return;
		}
	}

	if(zeroCount){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
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
