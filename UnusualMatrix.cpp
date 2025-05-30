#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool checkerFn(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB){
	int n = matrixA.size();
	for(int j=0;j<n;j++){
		if(matrixA[0][j] != matrixB[0][j]){
			for(int i=0;i<n;i++){
				matrixA[i][j] ^= 1;
			}
		}
	}

	for(int i=0;i<n;i++){
		int needXOR = matrixA[i][0] ^ matrixB[i][0];
		for(int j=0;j<n;j++){
			if(matrixA[i][j]^matrixB[i][j] != needXOR){
				return false;
			}
		}
	}
	return true;
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> matrixA(n, vector<int>(n));
	vector<vector<int>> matrixB(n, vector<int>(n));

	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			matrixA[i][j] = s[j] - '0';
		}
	}

	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			matrixB[i][j] = s[j] - '0';
		}
	}

	if(checkerFn(matrixA, matrixB)){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
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
