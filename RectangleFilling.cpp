#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        
        vector<vector<char>> grid(n, vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }

        bool flag = false;

        if(grid[0][0] == grid[n-1][m-1] || grid[0][m-1] == grid[n-1][0]){
            flag=true;
        }

        if(grid[0][0] == grid[0][m-1]){
            char x = grid[0][0];
            bool found = false;
            for(int i=0;i<m;i++){
                if(grid[n-1][i]==x){
                    found = true;
                    break;
                }
            }
            if(found){
                flag=true;
            }
        }

        if(grid[n-1][0] == grid[n-1][m-1]){
            char x = grid[n-1][0];
            bool found = false;
            for(int i=0;i<m;i++){
                if(grid[0][i]==x){
                    found = true;
                    break;
                }
            }
            if(found){
                flag=true;
            }
        }

        if(grid[0][0] == grid[n-1][0]){
            char x = grid[0][0];
            bool found = false;
            for(int i=0;i<n;i++){
                if(grid[i][m-1]==x){
                    found = true;
                    break;
                }
            }
            if(found){
                flag=true;
            }
        }

        if(grid[0][m-1] == grid[n-1][m-1]){
            char x = grid[0][m-1];
            bool found = false;
            for(int i=0;i<n;i++){
                if(grid[i][0]==x){
                    found = true;
                    break;
                }
            }
            if(found){
                flag=true;
            }
        }

        if(flag){
            cout<<"YES"<<endl;
        }

        else{
            cout<<"NO"<<endl;
        }
    }
}