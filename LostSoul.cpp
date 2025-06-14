#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;

	vector<int> numsA(n+1);
	vector<int> numsB(n+1);

	for(int i=1;i<=n;i++){
		cin>>numsA[i];
	}

	for(int i=1;i<=n;i++){
		cin>>numsB[i];
	}

	vector<int> prevOccurenceA(n+1, -1);
	vector<int> prevOccurenceB(n+1, -1);

	int ans = 0;
	for(int i=1;i<=n;i++){
		if(numsA[i]==numsB[i]){
			ans = max(ans, i);
		}
		if(prevOccurenceA[numsA[i]]!=-1){
			ans = max(ans, prevOccurenceA[numsA[i]]);
		}
		if(prevOccurenceB[numsB[i]]!=-1){
			ans = max(ans, prevOccurenceB[numsB[i]]);
		}
		if(prevOccurenceB[numsA[i]]!=i-1){
			ans = max(ans, prevOccurenceB[numsA[i]]);
		}
		if(prevOccurenceA[numsB[i]]!=i-1){
			ans = max(ans, prevOccurenceA[numsB[i]]);
		}
		prevOccurenceA[numsA[i]] = i;
		prevOccurenceB[numsB[i]] = i;
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
