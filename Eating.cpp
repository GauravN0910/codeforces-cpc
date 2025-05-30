#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int n, q;
	cin>>n>>q;

	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}

	vector<int> prefixXOR(n);
	prefixXOR[0] = nums[0];
	for(int i=1;i<n;i++){
		prefixXOR[i] = prefixXOR[i-1] ^ nums[i];
	}

	vector<vector<int>> last(n, vector<int>(31, 0));
	for(int i=1;i<n;i++){
		if(i){
			last[i] = last[i-1];
		}
		last[i][__lg(nums[i])] = i;
		for(int bit=29;bit>=0;bit--){
			/*Last index with Bit number >= bit set*/
			last[i][bit] = max(last[i][bit], last[i][bit+1]);
		}
	}

	while(q--){
		int val;
		cin>>val;
		int idx = n-1;
		while(idx>=0 && val>0){
			int msb = __lg(val);
			int next = last[idx][msb];
			val = (val ^ prefixXOR[next] ^ prefixXOR[idx]);
			idx = next;

			if(next==-1 || nums[next]>val){
				break;
			} 
			idx -= 1;
			val ^= nums[next];
		}
		cout<<n - idx - 1<<" ";
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
