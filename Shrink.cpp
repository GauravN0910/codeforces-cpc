#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;

	vector<int> ans(n);

	ans[0] = 1;
	int curNum = n;
	for(int i=1;i<n;i++){
		ans[i] = curNum;
		curNum--;
	}

	for(int i=0;i<n;i++){
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

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
