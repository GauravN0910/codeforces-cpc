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

	vector<long long> bitCount(32, 0);

    for(long long i=0;i<n;i++){
        for(long long j=0;j<32;j++){
            if(nums[i] & (1<<j)){
                bitCount[j]++;
            }
        }
    }

    long long ans = 0;

    for(long long i=0;i<n;i++){
        long long maxVal = 0;
        for(long long bit=0;bit<32;bit++){
            long long power;
            if(nums[i] & (1<<bit)){
                power = n - bitCount[bit];
            }
            else{
                power = bitCount[bit];
            }
            maxVal += (1<<bit) * power;
        }
        ans = max(ans, maxVal);
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
