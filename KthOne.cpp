#include<bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<int> sum;

    void init(int n){
        size = 1;
        while(size<n){
            size = size*2;
        }
        sum.resize(size*2);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            sum[x] = v;
            return;
        }

        int mid = (lx+rx)/2;
        if(i<mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else{
            set(i, v, 2*x+2, mid, rx);
        }
        sum[x] = sum[2*x+1] + sum[2*x+2];
    }

    void set(int i, int v){
        return set(i, v, 0, 0, size);
    }

    void flip(int i, int x, int lx, int rx){
        if(rx-lx==1){
            sum[x] = 1 - sum[x];
            return;
        }
        int mid = (lx+rx)/2;
        if(i<mid){
            flip(i, 2*x+1, lx, mid);
        }
        else{
            flip(i, 2*x+2, mid, rx);
        }
        sum[x] = sum[2*x+1] + sum[2*x+2];
    }

    void flip(int i){
        return flip(i, 0, 0, size);
    }

    int find(int k, int x, int lx, int rx){
        if(rx-lx==1){
            return lx;
        }

        int mid = (lx+rx)/2;
        int sl = sum[2*x+1];
        if(k<sl){
            return find(k, 2*x+1, lx, mid);
        }
        else{
            return find(k-sl, 2*x+2, mid, rx);
        }   
    }

    int find(int k){
        return find(k, 0, 0, size);
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
            int i;
            cin>>i;
            st.flip(i);
        }
        else{
            int k;
            cin>>k;
            cout<<st.find(k)<<endl;
        }
    }
}