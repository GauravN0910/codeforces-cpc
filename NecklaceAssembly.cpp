#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
	long long n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<long long> count(26);
	for(long long i=0;i<n;i++){
		long long x = s[i] - 'a';
		count[x]++;
	}
	
	for(long long size=n;size>=1;size--){
		vector<bool> visited(size);
		vector<long long> cycles;

		for(long long i=0;i<size;i++){
			if(visited[i]){
				continue;
			}
			visited[i] = true;
			long long nextIdx = (i + k)%size;
			long long count = 1;
			while(!visited[nextIdx]){
				count++;
				visited[nextIdx] = true;
				nextIdx = (nextIdx + k)%size;
			}
			cycles.push_back(count);
		}

		priority_queue<long long> tempCount(count.begin(), count.end());
		sort(cycles.begin(), cycles.end());
		bool flag = true;
		while(!cycles.empty()){
			if(tempCount.top()<cycles.back()){
				flag = false;
				break;
			}
			else{
				long long x = tempCount.top();
				tempCount.pop();
				x -= cycles.back();
				tempCount.push(x);
				cycles.pop_back();
			}
		}
		if(flag){
			cout<<size<<endl;
			return;
		}
	} 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}
