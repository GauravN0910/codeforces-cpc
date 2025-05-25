#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;
	vector<long long> nums(n);
	long long ans = 0;
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}

	if(n<3){
		for(int i=0;i<n;i++){
			ans |= nums[i];
		}
		cout<<ans<<endl;
		return;
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				ans = max(ans, nums[i] | nums[j] | nums[k]);
			}
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
