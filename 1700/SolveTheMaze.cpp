#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<char>> maze(n, vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }

    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(maze[x][y]=='B'){
                for(auto [dx, dy]:directions){
                    int i = x + dx;
                    int j = y + dy;
                    if(i>=0 && j>=0 && i<n && j<m && maze[i][j]=='.'){
                        maze[i][j] = '#';
                    }
                }
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, 0));

    if(maze[n-1][m-1]!='#'){
        q.push({n-1, m-1});
        visited[n-1][m-1] = 1; 
    }


    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(auto [dx, dy]:directions){
            int i = x + dx;
            int j = y + dy;
            if(i>=0 && j>=0 && i<n && j<m && maze[i][j]!='#' && !visited[i][j]){
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == 'G' && !visited[i][j]){
                cout<<"NO"<<endl;
                return;
            }
            else if(maze[i][j] == 'B' && visited[i][j]){
                cout<<"NO"<<endl;
                return;
            }
        }   
    }
    cout<<"YES"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}