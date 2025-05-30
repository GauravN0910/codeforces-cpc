#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;

    vector<long long> rows(n);
    vector<long long> columns(n);
    multiset<long long> row;
    multiset<long long> column;

    for(long long i=0;i<n;i++){
        cin>>rows[i]>>columns[i];
        row.insert(rows[i]);
        column.insert(columns[i]);
    }

    if(n==1){
        cout<<1<<endl;
        return;
    }

    long long ans = 1e18;
    for(long long i=0;i<n;i++){
        row.erase(row.find(rows[i]));
        column.erase(column.find(columns[i]));

        long long height = *row.rbegin() - *row.begin() + 1;
        long long width = *column.rbegin() - *column.begin() + 1;

        if(height*width==n-1){
            ans = min(ans, height*(width + 1));
            ans = min(ans, (height + 1)*width);
        }
        else{
            ans = min(ans, height*width);
        }
        row.insert(rows[i]);
        column.insert(columns[i]);
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