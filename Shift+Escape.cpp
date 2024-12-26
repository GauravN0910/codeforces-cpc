#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long n, m, k;

long long dp[205][205][205][2];

long long dfs(vector<vector<long long>>& grid, long long row, long long col, long long numShifts, long long picked){
    if((row==n && col==m-1) || (row==n-1 && col==m)){
        return 0;
    }

    if(row>=n || col>=m){
        return 1e18;
    }

    if(dp[row][col][numShifts][picked]!=-1){
        return dp[row][col][numShifts][picked];
    }

    long long sameRowShift = 1e18;
    if(numShifts<m && picked==0){
        sameRowShift = k + dfs(grid, row, col, numShifts+1, picked);
    }

    long long goRight = grid[row][(col+numShifts)%m] + dfs(grid, row, col+1, numShifts, 1);
    long long goDown = grid[row][(col+numShifts)%m] + dfs(grid, row+1, col, 0, 0);

    return dp[row][col][numShifts][picked] = min({sameRowShift, goRight, goDown});
}

void solve(){
    cin>>n>>m>>k;

    vector<vector<long long>> grid(n+1, vector<long long>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int x=0;x<=m;x++){
                for(int y=0;y<2;y++){
                    dp[i][j][x][y] = -1;
                }
            }
        }
    }   

    long long ans = dfs(grid, 0, 0, 0, 0);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}