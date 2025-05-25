#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;

	vector<int> ans;
	int curPower = 1;
	while(n>=curPower){
		ans.push_back(curPower);
		n -= curPower;
		curPower *= 2;
	}
	if(n){
		ans.push_back(n);
	}
	int sz = ans.size();
	sort(ans.begin(), ans.end());
	cout<<sz - 1<<endl;
	for(int i=1;i<sz;i++){
		cout<<ans[i] - ans[i-1]<<" ";
	}
	cout<<endl;
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
