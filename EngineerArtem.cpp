#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n, m;
	cin>>n>>m;

	vector<vector<int>> matrix(n, vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i%2==j%2){
				if(matrix[i][j]%2){
					matrix[i][j]++;
				}
			}
			else{
				if(matrix[i][j]%2==0){
					matrix[i][j]++;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<matrix[i][j]<<" ";
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
