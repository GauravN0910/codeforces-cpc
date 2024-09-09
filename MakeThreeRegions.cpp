#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> grid(2);

        for(int i=0;i<2;i++){
            string s;
            cin>>s;
            grid[i] = s;
        }
        
        int ans = 0;
        for(int i=1;i<n-1;i++){
            if(grid[0][i]=='.' && grid[1][i]=='.' && ((grid[0][i-1]=='.' && grid[0][i+1]=='.' && grid[1][i-1]=='x' && grid[1][i+1]=='x') || (grid[1][i-1]=='.' && grid[1][i+1]=='.' && grid[0][i-1]=='x' && grid[0][i+1]=='x'))){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}