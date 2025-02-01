#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, m;
    cin>>n>>m;
    string s;
    cin>>s;

    vector<vector<long long>> grid(n, vector<long long>(m));
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    long long x = 0;
    long long y = 0;
    for(auto move:s){
        if(move=='D'){
            long long sum = 0;
            for(long long i=0;i<m;i++){
                sum += grid[x][i];
            }
            grid[x++][y] -= sum;
        }
        else{
            long long sum = 0;
            for(long long i=0;i<n;i++){
                sum += grid[i][y];
            }
            grid[x][y++] -= sum;
        }
    }

    long long sum = 0;

    for(long long i=0;i<n;i++){
        sum += grid[i][m-1];
    }

    grid[n-1][m-1] -= sum;

    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}