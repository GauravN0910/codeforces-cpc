#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

struct item{
    long long count, maxVal, minPrefix, maxPrefix, minSuffix, maxSuffix;
};

struct segtree{
    long long size;
    vector<item> values;

    item merge(item left, item right){
        return {
            left.count + right.count,
            max({left.maxVal, right.maxVal, right.maxPrefix - left.minSuffix - 1, left.maxSuffix - right.minPrefix - 1}),
            min(left.minPrefix, left.count + right.minPrefix),
            max(left.maxPrefix, right.maxPrefix - left.count),
            min(right.minSuffix, right.count + left.minSuffix),
            max(right.maxSuffix, left.maxSuffix - right.count)
        };
    }

    item single(long long v){
        return {1, 0, v, v, v, v};
    }

    void init(long long n){
        size = n;
        values.resize(size*4);
    }

    void set(long long i, long long v, long long x, long long lx, long long rx){
        if(rx==lx){
            values[x] = single(v);
            return;
        }
        long long mid = (lx+rx)/2;
        if(i<=mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else{
            set(i, v, 2*x+2, mid+1, rx);
        }
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }

    void set(long long i, long long v){
        return set(i, v, 0, 0, size-1);
    }

    long long getMax(){
        return values[0].maxVal;
    }
};

void solve(){
    long long n, q;
    cin>>n>>q;

    segtree SegTree;
    SegTree.init(n);
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        SegTree.set(i, x);
    }

    long long ans = SegTree.getMax();
    cout<<ans<<endl;

    for(int i=0;i<q;i++){
        long long idx; cin>>idx;
        idx--;
        long long val; cin>>val;
        SegTree.set(idx, val);
        ans = SegTree.getMax();
        cout<<ans<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}