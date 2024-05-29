#include<bits/stdc++.h>
using namespace std;

struct segtree{
    int size;
    vector<int> values;

    void init(int n){
        size = 1;
        while(size<n){
            size = size*2;
        }
        values.resize(size*2);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            values[x] = v;
            return;
        }

        int mid = (lx+rx)/2;
        if(i<mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else{
            set(i, v, 2*x+2, mid, rx);
        }

        values[x] = max(values[2*x+1], values[2*x+2]);
    }

    void set(int i, int v){
        return set(i, v, 0, 0, size);
    }

    int findFirst(int v, int x, int lx, int rx){
        if(values[x]<v){
            return -1;
        }
        if(rx-lx==1){
            return lx;
        }   
        int mid = (lx+rx)/2;
        int ans = findFirst(v, 2*x+1, lx, mid);
        if(ans==-1){
            ans = findFirst(v, 2*x+2, mid, rx);
        }
        return ans;
    }

    int findFirst(int v){
        return findFirst(v, 0, 0, size);
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
            int v;
            cin>>v;
            cout<<st.findFirst(v)<<endl;
        }
    }
}