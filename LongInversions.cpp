#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans;
	for(int k=1;k<=n;k++){
	    vector<int> v(k);
	    for(int i=0;i<n;i++){
	    	v[i%k] ^= '1' - s[i];
	    }

	    if(v==vector(k, v[0])){
	    	ans = k;
	    }
	}
	cout<<ans<<endl;
    }
}
