#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
	long long x, y, z;
	cin>>x>>y>>z;

	vector<long long> numsX(x);
	vector<long long> numsY(y);
	vector<long long> numsZ(z);

	long long sum = 0; 
	vector<long long> sums(3);

	for(long long i=0;i<x;i++){
		cin>>numsX[i];
		sum += numsX[i];
		sums[0] += numsX[i];
	}
	for(long long i=0;i<y;i++){
		cin>>numsY[i];
		sum += numsY[i];
		sums[1] += numsY[i];
	}
	for(long long i=0;i<z;i++){
		cin>>numsZ[i];
		sum += numsZ[i];
		sums[2] += numsZ[i];
	}

	sort(numsX.begin(), numsX.end());
	sort(numsY.begin(), numsY.end());
	sort(numsZ.begin(), numsZ.end());

	vector<long long> firstElems;
	firstElems.push_back(numsX[0]);
	firstElems.push_back(numsY[0]);
	firstElems.push_back(numsZ[0]);

	sort(firstElems.begin(), firstElems.end());
	sort(sums.begin(), sums.end());

	sum -= 2*(firstElems[0] + firstElems[1]);
	long long ans = max(sum, sums[2] + sums[1] - sums[0]);
	cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t = 1;
    while(t--){
        solve();
    }
}
