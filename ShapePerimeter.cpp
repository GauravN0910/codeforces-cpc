#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;

    int prevRow;
    cin>>prevRow;
    int prevCol;
    cin>>prevCol;

    int perimeter = 4*m;
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        perimeter += 4*m;
        perimeter -= 2 * max(0, m - x);
        perimeter -= 2 * max(0, m - y);
        prevRow = x;
        prevCol = y;
    }

    cout<<perimeter<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}