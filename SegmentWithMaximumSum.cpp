#include<bits/stdc++.h>
using namespace std;

struct item{
    long long seg, pref, suf, sum;
};

struct segtree{
    int size;
    vector<item> values;

    item merge(item a, item b){
        return {
            max({a.seg, b.seg, a.suf+b.pref}),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        };
    }

    item single(int v){
        if(v<=0){
            return {0, 0, 0, v};
        }
        else{
            return {v, v, v, v};
        }
    }

    void init(int n){
        size = 1;
        while(size<n){
            size = size*2;
        }
        values.resize(size*2);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            values[x] = single(v);
            return;
        }
        int mid = (lx+rx)/2;
        if(i<mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else{
            set(i, v, 2*x+2, mid, rx);
        }
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }

    void set(int i, int v){
        return set(i, v, 0, 0, size);
    }

    item maxSum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return {0, 0, 0, 0,};
        }
        if(lx>=l && rx<=r){
            return values[x];
        }

        int mid = (lx+rx)/2;
        item left = maxSum(l, r, 2*x+1, lx, mid);
        item right = maxSum(l, r, 2*x+2, mid, rx);
        return merge(left, right);
    }

    item maxSum(int l, int r){
        return maxSum(l, r, 0, 0, size);
    }
};

int main(){
    int n, m;
    cin>>n>>m;

    segtree st;
    st.init(n);

    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        st.set(i, v);
    }

    cout<<st.maxSum(0, n).seg<<endl;
    while(m--){
        int i, v;
        cin>>i>>v;
        st.set(i, v);   
        cout<<st.maxSum(0, n).seg<<endl;
    }
}