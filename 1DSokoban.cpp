#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int helperFn(vector<int>& boxes, vector<int>& special){
	int n = boxes.size();
	int m = special.size();

	vector<int> suffixSum(n+1, 0);
	/*Finding number of boxes already in special positions*/
	int right = m-1;
	for(int i=n-1;i>=0;i--){
		suffixSum[i] = suffixSum[i+1];
		while(right>=0 && special[right]>boxes[i]){
			right--;
		} 
		if(right>=0 && special[right]==boxes[i]){
			suffixSum[i]++;
		}
	}

	int ans = suffixSum[0];
	int bIdx = 0;
	int numBoxes = 0;
	int left = 0;

	for(int right=0;right<m;right++){
		while(bIdx<n && boxes[bIdx] <= special[right]){
			bIdx++;
			numBoxes++;
		}
		while(left<m && special[right] - special[left] + 1 > numBoxes){
			left++;
		}
		ans = max(ans, right - left + 1 + suffixSum[bIdx]);
	}
	return ans;
}

void solve(){
	int n, m;
	cin>>n>>m;
	
	vector<int> boxes;
	vector<int> special;
	vector<int> boxesNeg;
	vector<int> specialNeg;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x>0){
			boxes.push_back(x);
		}
		else{
			boxesNeg.push_back(-x);
		}
	}

	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		if(x>0){
			special.push_back(x);
		}
		else{
			specialNeg.push_back(-x);
		}
	}

	reverse(boxesNeg.begin(), boxesNeg.end());
	reverse(specialNeg.begin(), specialNeg.end());

	int negAns = helperFn(boxesNeg, specialNeg);
	int posAns = helperFn(boxes, special);
	int ans = negAns + posAns;
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
