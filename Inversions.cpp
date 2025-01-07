#include<bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<int> sums;

    void init(int n) {
        size = n;
        sums.resize(4 * n, 0);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if (lx > r || rx < l) {
            return 0;
        }

        if (lx >= l && rx <= r) {
            return sums[x];
        }

        int mid = (lx + rx) / 2;

        int left = sum(l, r, 2 * x + 1, lx, mid);
        int right = sum(l, r, 2 * x + 2, mid + 1, rx);

        return left + right;
    }

    void set(int index, int value, int x, int lx, int rx) {
        if (lx == rx) {
            sums[x] += value;
            return;
        }

        int mid = (lx + rx) / 2;
        if (index <= mid) {
            set(index, value, 2*x+1, lx, mid);
        }
        else {
            set(index, value, 2*x+2, mid+1, rx);
        }

        sums[x] = sums[x * 2 + 1] + sums[x * 2 + 2];

        return;
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size-1);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size - 1);
    }
};
void solve(){
    int n;
    cin>>n;

    SegTree segTree;
    segTree.init(n+1);

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        int ans = segTree.sum(num+1, n);
        segTree.set(num, 1);
        cout<<ans<<" ";
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