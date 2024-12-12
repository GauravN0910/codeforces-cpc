#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct segtree{
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

    long long sum(int l, int r, int x, int lx, int rx){
        if(lx>=r || l>=rx){
            return 0;
        }
        if(lx>=l && rx<=r){
            return gcds[x];
        }

        int mid = (lx+rx)/2;
        long long left = sum(l, r, 2*x+1, lx, mid);
        long long right = sum(l, r, 2*x+2, mid, rx);
        return __gcd(left, right);
    }

    long long sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }

};

void solve(){
    int n, q;
    cin>>n>>q;

    segtree st;
    st.init(n);

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> differenceArray(n);
    for(int i=0;i<n-1;i++){
        differenceArray[i] = abs(nums[i] - nums[i+1]);
    }
    
    for(int i=0;i<n-1;i++){
        st.set(i, differenceArray[i]);
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        cout<<st.sum(l, r)<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}