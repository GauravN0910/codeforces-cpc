#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n, m;
	cin>>n>>m;
	vector<string> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	vector<vector<string>> b(m, vector<string>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>b[i][j];
		}
	}

    int maxMatch = 0;

    vector<int> visited(n, 0);

	for(int i=0;i<m;i++){
		int count = 0;
		for(int j=0;j<n;j++){
			if(a[j]==b[i][j]){
				count++;
                visited[j] = 1;
			}
		}
		maxMatch = max(count, maxMatch);
	}

    for(int i=0;i<n;i++){
        if(visited[i]==0){
            cout<<-1<<endl;
            return;
        }
    }

	int ans = n + 2*(n-maxMatch);
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
