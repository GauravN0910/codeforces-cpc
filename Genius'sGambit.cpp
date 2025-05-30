#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
	int a, b, k;
	cin>>a>>b>>k;

	vector<int> x(a+b, 0);
	for(int i=0;i<b;i++){
		x[i] = 1;
	}
	vector<int> y = x;

	int lastOneIdx = b-1;

	if(k==0 && a==0){
		cout<<"YES"<<endl;
		for(auto bit:x){
			cout<<bit;
		}
		cout<<endl;

		for(auto bit:y){
			cout<<bit;
		}
		cout<<endl;
		return;
	}
	
	if(lastOneIdx==0 && k!=0){
		cout<<"NO"<<endl;
		return;
	}

	if(a==0 && k!=0){
		cout<<"NO"<<endl;
		return;
	}

	if(a + b - 2 < k){
		cout<<"NO"<<endl;
		return;
	}
	
	
	int right = lastOneIdx + min(k, a);
	k -= min(k, a);
	swap(y[lastOneIdx], y[right]);
	lastOneIdx--;

	while(k){
		swap(y[lastOneIdx] ,y[lastOneIdx + 1]);
		lastOneIdx--;
		k--;
	}

	cout<<"YES"<<endl;
	for(auto bit:x){
		cout<<bit;
	}
	cout<<endl;

	for(auto bit:y){
		cout<<bit;
	}
	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t = 1;
    while(t--){
        solve();
    }
}
