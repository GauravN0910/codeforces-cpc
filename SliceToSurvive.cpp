#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n, m, a, b;
	cin>>n>>m>>a>>b;

	vector<pair<int, int>> ways;
	int ans = 1e9;

	ways.push_back({a, m});
	ways.push_back({n, b});
	ways.push_back({n-a+1, m});
	ways.push_back({n, m-b+1});

	for(auto [x, y]:ways){
		int tempAns = 0;
		while(x>1){
			x = (x+1)/2;
			tempAns++;
		}
		while(y>1){
			y = (y+1)/2;
			tempAns++;
		}
		ans = min(ans, 1 + tempAns);
	}

	cout<<ans<<endl;
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
