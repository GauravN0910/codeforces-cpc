#include<bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<long long> mins;

    void init(int n){
        size = 1;
        while(size<n){
            size = size*2;
        }
        mins.assign(size*2, INT_MAX);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            mins[x] = v;
            return;
        }
        int mid = (lx+rx)/2;
        if(i<mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else{
            set(i, v, 2*x+2, mid, rx);
        }
        mins[x] = min(mins[2*x+1], mins[2*x+2]);
    }

    void set(int i, int v){
        return set(i, v, 0, 0, size);
    }

    long long minimize(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return INT_MAX;
        }
        if(lx>=l && rx<=r){
            return mins[x];
        }

        int mid = (lx+rx)/2;
        long long left = minimize(l, r, 2*x+1, lx, mid);
        long long right = minimize(l, r, 2*x+2, mid, rx);
        return min(left, right);
    }

    long long minimize(int l, int r){
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
            cout<<st.minimize(l, r)<<endl;
        }
    }
}