#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    set<int> strangers;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            strangers.insert(grid[i][j]);
        }
    }

    set<int> nonStrangers;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0 && grid[i][j]==grid[i-1][j]){
                nonStrangers.insert(grid[i][j]);
                if(strangers.find(grid[i][j])!=strangers.end()){
                    strangers.erase(strangers.find(grid[i][j]));
                }
            }
            else if(i<n-1 && grid[i][j]==grid[i+1][j]){
                nonStrangers.insert(grid[i][j]);
                if(strangers.find(grid[i][j])!=strangers.end()){
                    strangers.erase(strangers.find(grid[i][j]));
                }
            }
            else if(j>0 && grid[i][j]==grid[i][j-1]){
                nonStrangers.insert(grid[i][j]);
                if(strangers.find(grid[i][j])!=strangers.end()){
                    strangers.erase(strangers.find(grid[i][j]));
                }
            }
            else if(j<m-1 && grid[i][j]==grid[i][j+1]){
                nonStrangers.insert(grid[i][j]);
                if(strangers.find(grid[i][j])!=strangers.end()){
                    strangers.erase(strangers.find(grid[i][j]));
                }
            }
        }
    }

    int twoMoves = nonStrangers.size();
    int oneMove = strangers.size();

    int ans = (twoMoves-1)*2 + oneMove;
    if(twoMoves==0){
        ans = oneMove - 1;
    }
    cout<<ans<<endl;
}
   
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}