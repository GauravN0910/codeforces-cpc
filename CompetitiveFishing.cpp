#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n , k;
	cin >> n >> k;
 
 
	string s;
	cin >> s;
 
 
	vector<long long> suffixSum(n, 0);
	vector<long long> a;
 
 
	for(int i = 0 ; i < n ; i ++)
	{
		if(s[i] == '0')
		{
			suffixSum[i] = -1;
		}
		else
		{
			suffixSum[i] = 1;
		}
	}
 
 
	for(int i = n-2 ; i >= 0 ; i --)
	{
		suffixSum[i] += suffixSum[i+1];
	}
 
	for(int i = 1 ; i < n ; i ++)
	{
		a.push_back(suffixSum[i]);
	}
 
 
	sort(a.begin() , a.end());
	reverse(a.begin() , a.end());
 
	long long gp = 1;
 
	for(long long x : a)
	{
		k -= x;
		gp++;
 
		if(k <= 0)
		{
			cout << gp << endl;
			return;
		}
	}
 
 
	cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}