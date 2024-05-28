#include<bits/stdc++.h>
using namespace std;

struct item{
    int m, c;
};

struct segtree{
    int size;
    vector<item> values;

    item merge(item a, item b){
        if(a.m < b.m){
            return a;
        }
        if(a.m > b.m){
            return b;
        }
        return {a.m, a.c+b.c};
    }

    item single(int v){
        return {v, 1};
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

    item minimize(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return {INT_MAX, 0};
        }
        if(lx>=l && rx<=r){
            return values[x];
        }

        int mid = (lx+rx)/2;
        item left = minimize(l, r, 2*x+1, lx, mid);
        item right = minimize(l, r, 2*x+2, mid, rx);
        return merge(left, right);
    }

    item minimize(int l, int r){
        return minimize(l, r, 0, 0, size);
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

    while(m--){
        int opType;
        cin>>opType;
        if(opType==1){
            int i, v;
            cin>>i>>v;
            st.set(i, v);
        }
        else{
            int l, r;
            cin>>l>>r;
            auto x = st.minimize(l, r);
            cout<<x.m<<" "<<x.c<<endl;
        }
    }
}