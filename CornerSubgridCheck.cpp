#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> count(n, vector<int>(n, 0));
    vector<string> grid(n);
    vector<int> charMap[k][n];
    for(int i=0;i<n;i++){
        cin>>grid[i];
        for(int j=0;j<n;j++){
            charMap[grid[i][j] - 'A'][i].push_back(j);
        }
    }

    for(int x=0;x<k;x++){
        bool found = false;
        for(int i=0;i<n;i++){
            if(found){
                break;
            }
            int sz = charMap[x][i].size();
            for(int j=0;j<sz;j++){
                if(found){
                    break;
                }
                for(int k=j+1;k<sz;k++){
                    if(found){
                        break;
                    }
                    int a = charMap[x][i][j];
                    int b = charMap[x][i][k];
                    if((count[a][b]>>x)&1){
                        found = true;
                    }
                    count[a][b] |= (1<<x);
                }
            }
        }
        
        if(found){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t = 1;
    while(t--){
        solve();
    }
}