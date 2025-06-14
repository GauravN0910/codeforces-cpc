#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

struct segTree{
    long long size;
    vector<long long> sums;

    void init(long long n){
        size = 1;
        while(size<n){
            size = size*2;
        }
        sums.assign(2*size, 0LL);
    }

    void set(long long i, long long v, long long x, long long lx, long long rx){
        if(rx-lx==1){
            sums[x] = v;
            return;
        }
        long long mid = (lx + rx)/2;
        if(i<mid){
            set(i, v, 2*x+1, lx, mid);
        }
        else{
            set(i, v, 2*x+2, mid, rx);
        }
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void set(long long i, long long v){
        return set(i, v, 0, 0, size);
    }

    long long sum(long long l, long long r, long long x, long long lx, long long rx){
        if(lx>=r || l>=rx){
            return 0;
        }
        if(lx>=l && rx<=r){
            return sums[x];
        }

        long long mid = (lx+rx)/2;
        long long left = sum(l, r, 2*x+1, lx, mid);
        long long right = sum(l, r, 2*x+2, mid, rx);
        return left+right;
    }

    long long sum(long long l, long long r){
        return sum(l, r, 0, 0, size);
    }

};


void solve(){
    long long n;
    cin>>n;
    string s;
    cin>>s;

    string revS = s;
    reverse(revS.begin(), revS.end());
    vector<vector<long long>> countMap(30);
    vector<vector<long long>> countMapRev(30);
    for(long long i=0;i<n;i++){
        countMap[s[i] - 'a'].push_back(i);
        countMapRev[revS[i] - 'a'].push_back(i);
    }

    for(long long i=0;i<26;i++){
        reverse(countMap[i].begin(), countMap[i].end());
    }

    vector<long long> permutation(n);

    for(long long i=0;i<n;i++){
        long long finalChar = revS[i] - 'a';
        permutation[countMap[finalChar].back()] = i;
        countMap[finalChar].pop_back();
    }

    segTree sumTree;
    sumTree.init(n);

    long long ans = 0;
    for(long long i=0;i<n;i++){
        long long left = permutation[i];
        long long result = sumTree.sum(left + 1, n);
        ans += result;
        sumTree.set(left, 1);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t = 1;
    while(t--){
        solve();
    }
}