#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, m, k;
    cin>>n>>m>>k;

    set<long long> vertical;
    set<long long> horizontal;
    vector<long long> vert(n);
    vector<long long> hor(m);
    vector<pair<long long, long long>> points;
    for(long long i=0;i<n;i++){
        cin>>vert[i];
        vertical.insert(vert[i]);
    }

    for(long long i=0;i<m;i++){
        cin>>hor[i];
        horizontal.insert(hor[i]);
    }

    for(long long i=0;i<k;i++){
        long long a, b;
        cin>>a>>b;
        if(vertical.count(a) && horizontal.count(b)){
            continue;
        }
        points.push_back({a, b});
    }

    map<long long, long long> countX;
    map<long long, long long> countY;
    long long ans = 0;
    map<pair<long long, long long>, long long> column;
    map<pair<long long, long long>, long long> row;

    for(auto [a, b]:points){
        if(!horizontal.count(b)){
            long long idx = upper_bound(hor.begin(), hor.end(), b) - hor.begin();
            ans += countY[idx];
            countY[idx]++;
            row[{idx, a}]++;
        }
        if(!vertical.count(a)){
            long long idx = upper_bound(vert.begin(), vert.end(), a) - vert.begin();
            ans += countX[idx];
            countX[idx]++;
            column[{idx, b}]++;
        }
    }

    for(auto [x, val]:column){
        ans -= (val*(val-1))/2;
    }
    for(auto [x, val]:row){
        ans -= (val*(val-1))/2;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}