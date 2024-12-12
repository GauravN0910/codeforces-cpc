#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
long long INF = 1e18;

long long powerOf2[200005];

void solve(){
    long long n, k;
    cin>>n>>k;



    if(k>powerOf2[n]){
		cout <<-1<< endl;
		return;
	}

    long long left = 0;
    long long right = n-1;
    vector<long long> ans(n, 0);
    long long curNum = 1LL;

    while(left<=right){
        long long size = (right - left + 1);
        if(powerOf2[size - 1]>=k){
            ans[left] = curNum;
            left++;
        }
        else{
            ans[right] = curNum;
            right--;
            k -= powerOf2[size - 1];
        }
        curNum++;
    }

    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<200005;i++){
		powerOf2[i] = 1LL;
	}
 
	for(int i=2;i<200005;i++){
		powerOf2[i] = 2*powerOf2[i-1];
		powerOf2[i] = min(INF , powerOf2[i]);
	}
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}