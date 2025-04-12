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

	vector<long long> differenceArray(n-1);
	for(long long i=0;i<n-1;i++){
		differenceArray[i] = abs(nums[i] - nums[i+1]);
	}

    vector<set<long long>> visited(n);

	n -= 1;
    long long ans = 0;
    for(long long i=0;i<n;i++){
        long long curGCD = differenceArray[i];
        long long count = 0;
        for(long long j=i;j<n && curGCD!=1;j++){
            curGCD = __gcd(curGCD, differenceArray[j]);
            if(curGCD==1||visited[j].find(curGCD)!=visited[j].end()){
                break;
            }
            visited[j].insert(curGCD);
            count++;
        }
        ans = max(ans, count);
    }
    cout<<ans+1<<endl;
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
