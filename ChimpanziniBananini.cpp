#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
	long long q;
	cin>>q;

	long long rizz = 0;
	long long rizzRev = 0;
	long long total = 0;
	long long numElems = 0;

	deque<long long> dq, dqRev;

	while(q--){
		long long type;
		cin>>type;

		if(type==1){
			long long lastElem = dq.back();
			dq.pop_back();
			dq.push_front(lastElem);

			long long firstElem = dqRev.front();
			dqRev.pop_front();
			dqRev.push_back(firstElem);

			rizz += total;
			rizz -= numElems * lastElem;
			
			rizzRev -= total;
			rizzRev += numElems * firstElem;
		}

		else if(type==2){
			swap(rizz, rizzRev);
			swap(dq, dqRev);
		}
		else if(type==3){
			numElems++;
			long long num;
			cin>>num;
            dq.push_back(num);
            dqRev.push_front(num);
			rizz += num * numElems;
			rizzRev += (total + num);
			total += num;
		}
 		cout<<rizz<<endl;
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
