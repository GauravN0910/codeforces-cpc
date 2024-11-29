#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l, r, x;
    cin>>l>>r>>x;
    
    int minMexer = 0, mexL = 0;
    for (int idx = 31; idx >= 0; --idx) {
        int take = (x & (1 << idx)) > 0 ? 1 : 0;
        if (minMexer + (take * (1 << idx)) < l) {
            minMexer += take * (1 << idx);
        } else {
            take ^= 1;
            minMexer += take * (1 << idx);
            mexL += (1 << idx);
        }
    }

    minMexer = (1 << 32) - 1;
    int mexR = 0;
    for (int idx = 31; idx >= 0; --idx) {
        int take = (x & (1 << idx)) > 0 ? 0 : 1;
        if (minMexer - (take * (1 << idx)) > r) {
            minMexer -= take * (1 << idx);
        } else {
            take ^= 1;
            minMexer -= take * (1 << idx);
            mexR += (1 << idx);
        }
    }

    cout << min(mexL, mexR) << endl;
}

int main() {
	int t;  
	cin>>t;
	while(t--){
	    solve();
	}
}
