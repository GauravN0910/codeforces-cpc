#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct segmentTree{
    int size;
    vector<long long> gcds;

    void init(int n){
        size = 1;
        while(size<n){
            size = size*2;
        }
        gcds.assign(2*size, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            gcds[x] = v;
            return;
        }
        int mid = (lx + rx)/2;
        if(i<mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else{
            set(i, v, 2*x+2, mid, rx);
        }
        gcds[x] = __gcd(gcds[2*x+1], gcds[2*x+2]);
    }

    void set(int i, int v){
        return set(i, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx){
        if(lx>=r || l>=rx){
            return 0;
        }
        if(lx>=l && rx<=r){
            return gcds[x];
        }

        int mid = (lx+rx)/2;
        long long left = query(l, r, 2*x+1, lx, mid);
        long long right = query(l, r, 2*x+2, mid, rx);
        return __gcd(left, right);
    }

    long long query(int l, int r){
        return query(l, r, 0, 0, size);
    }

};

void solve(){
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}

	int gcdVal = 0;
	for(int i=0;i<n;i++){
		gcdVal = __gcd(gcdVal, nums[i]);
	}

	segmentTree segTree;
	segTree.init(2*n);

	for(int i=0;i<n;i++){
		nums[i] = nums[i]/gcdVal;
	}

    for(int i=0;i<n;i++){
        segTree.set(i, nums[i]);
    }


    for(int i=0;i<n;i++){
        segTree.set(i+n, nums[i]);
    }

	int low = 0;
	int high = n-1;
	int ans = high;

	while(low<=high){
		int mid = low + (high - low)/2;
		bool flag = true;
		for(int i=0;i<n;i++){
            int checkerGCD = 0;
			int left = i;
            int right = left + mid;

			int queryVal = segTree.query(left, right + 1);
			checkerGCD = __gcd(checkerGCD, queryVal);

            if(checkerGCD!=1){
                flag = false;
                break;
            }
		}

		if(flag){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}

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
