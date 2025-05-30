#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n, m, a, b;
	cin>>n>>m>>a>>b;

	if(!(m*b==n*a)){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	vector<vector<int>> ans(n, vector<int>(m, 0));

	int shift = 0;
	for(shift=1;shift<m;shift++){
		if((shift*n)%m==0){
			break;
		}
	}

	int dx = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a;j++){
			ans[i][(j+dx)%m] = 1;
		}
		dx += shift;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
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
