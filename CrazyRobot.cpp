#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve(){
	int n, m;
	cin>>n>>m;
	vector<string> grid(n);
	int labX = -1;
	int labY = -1;
	for(int i=0;i<n;i++){
		cin>>grid[i];
		for(int j=0;j<m;j++){
			if(grid[i][j] == 'L'){
				labX = i;
				labY = j;
			}
		}
	}

	vector<vector<int>> visited(n, vector<int>(m, 0));

	vector<vector<int>> moves(n, vector<int>(m, 0));

	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(grid[x][y]=='.'){
				for(auto [dx, dy]:directions){
					int i = x + dx;
					int j = y + dy;

					if(i>=0 && j>=0 && i<n && j<m){
						moves[x][y] += grid[i][j]!='#';
					}
				}
			}
		}
	}

    queue<pair<int, int>> q;
    q.push({labX, labY});
    visited[labX][labY] = 1;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        for(auto [dx, dy]:directions){
            int i = x + dx;
            int j = y + dy;

            if(i>=0 && j>=0 && i<n && j<m && !visited[i][j] && grid[i][j]!='#'){
                moves[i][j]--;
                if(moves[i][j]<=1){
                    visited[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && visited[i][j]){
                grid[i][j] = '+';
            }
        }
        cout<<grid[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
