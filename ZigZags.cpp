#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
	long long n;
	cin>>n;

	vector<long long> nums(n);
	for(long long i=0;i<n;i++){
		cin>>nums[i];
	}

    vector<long long> leftCount(n+1);
    
    long long ans = 0;
    for(long long j=0;j<n;j++){
        vector<long long> rightCount(n+1);
        for(long long k=n-1;k>=j+1;k--){
            ans += leftCount[nums[k]]*rightCount[nums[j]];
            rightCount[nums[k]]++;
        }
        leftCount[nums[j]]++;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}
