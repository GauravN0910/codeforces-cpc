#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
int adj[2000][2000];
int nums[1000010];
int idx = 0;

void init(){
    int N=3e5+5;
	vector<int> visited(N);
	for(int i=2;i<N;i++){
		if(!visited[i]){
			primes.push_back(i);
			for(int j=i;j<N;j+=i){
				visited[j]=1;
			}
		}
	}
}


void solve(){
    int n;
    cin>>n;
    int ans=1;
	while(1){
		if(ans&1){
			if(ans*(ans-1)/2+ans>=n-1) break;
		}else{
			if(ans*(ans-1)/2+ans-(ans-2)/2>=n-1) break;
		}
		ans++;
	}

    cout<<ans<<endl;
    
    for(int i=0;i<ans;i++){
        for(int j=0;j<ans;j++){
            adj[i][j] = 1;
        }
    }

    //Remove edges to make degree even for all node (To implement Fleury's algorithm)
    if(ans%2==0){
        for(int i=1;i<ans-2;i+=2){
            adj[i][i+1] = 0;
            adj[i+1][i] = 0;
        }
    }

    int idx=0;
	function<void(int)> fleury=[&](int u){
		for(int v=0;v<ans;v++){
			if(adj[u][v]){
                adj[u][v]=adj[v][u]=0;
                fleury(v);
            }
		}
		if(idx<n) nums[idx++]=u;
	};
	fleury(0);

    for(int i=0;i<n;i++){
        cout<<primes[nums[i]]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    init();
    while(t--){
        solve();
    }
}