#include<bits/stdc++.h>
using namespace std;

struct SegTree{
    int size;
    vector<int> sums;

    void init(int n){
        size = n;
        sums.resize(4*size, 0LL);
    }

    int walk(int sumReq, int sum, int x, int lx, int rx){
        if(lx==rx){
            return lx;
        }

        int mid = (lx + rx)/2;
        if(sums[2*x + 1]>=sumReq){
            return walk(sumReq, sum, 2*x+1, lx, mid);
        }
        return walk(sumReq - sums[2*x+1], sum, 2*x+2, mid+1, rx);
    }

    int walk(int sumReq){
        return walk(sumReq, 0, 0, 0, size-1);
    }

    int sum(int l, int r, int x, int lx, int rx){
        if(l>=lx && r<=rx){
            return sums[x];
        }
        if(l>rx || r<lx){
            return 0;
        }

        int mid = (lx + rx)/2;
        int left = sum(l, r, 2*x+1, lx, mid);
        int right = sum(l, r, 2*x+2, mid+1, rx);
        return left + right;
    }

    int sum(int l, int r){
        return sum(l, r, 0, 0, size-1);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx==lx){
            sums[x] = v;
            return;
        }

        int mid = (lx + rx)/2;
        if(i<=mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else{
            set(i, v, 2*x+2, mid+1, rx);
        }
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void set(int i, int v){
        return set(i, v, 0, 0, size-1);
    }
};

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    SegTree segTree;
    segTree.init(n);

    for(int i=0;i<n;i++){
        segTree.set(i, 1);
    }

    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        int x = segTree.walk(nums[i]+1);
        ans.push_back(n-x);
        segTree.set(x, 0);
    }

    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        solve();
    }
}