#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[1005][1005];

bool valid(int x, int y, int n, int m){
    return (x>=0 && x<n && y>=0 && y<m);
}

void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for(int i = 0 ; i <= n ; i ++)
	{
		for(int j = 0 ; j <= m ; j ++)
		{
			graph[i][j].clear();
		}
	}

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
        for(int j=0;j<m;j++){
            int x = i;
            int y = j;
            if(grid[i][j]=='L') y--;
            if(grid[i][j]=='R') y++;
            if(grid[i][j]=='U') x--;
            if(grid[i][j]=='D') x++;
            if(valid(x, y, n, m)){
                graph[x][y].push_back({i, j});
            }
        }
    }


    queue<pair<int, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && grid[i][j]=='U'){
                visited[i][j] = 1;
                q.push({i, j});
            }
            if(i==n-1 && grid[i][j]=='D'){
                visited[i][j] = 1;
                q.push({i, j});
            }
            if(j==0 && grid[i][j]=='L'){
                visited[i][j] = 1;
                q.push({i, j});
            }
            if(j==m-1 && grid[i][j]=='R'){
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        pair<int, int> position = q.front();
        q.pop();
        int x = position.first;
        int y = position.second;

        for(auto [i, j]:graph[x][y]){
            if(!visited[i][j]){
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='?'){
                bool flag = true;
                flag &= (i==0 || visited[i-1][j]);
                flag &= (i==n-1 || visited[i+1][j]);
                flag &= (j==0 || visited[i][j-1]);
                flag &= (j==m-1 || visited[i][j+1]);
                if(flag){
                    visited[i][j] = 1;
                }
            }
        }
    }

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}