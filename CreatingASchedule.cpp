#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin>>n>>m;

    vector<long long> classRooms;
    for(int i=0;i<m;i++){
        long long roomNumber;
        cin>>roomNumber;
        classRooms.push_back(roomNumber);
    }

    sort(classRooms.begin(), classRooms.end());

    vector<vector<long long>> ans(n+1, vector<long long>(6));

    for(int i=0;i<n;i+=2){
        int k = m - (i/2) - 1;
        for(int j=0;j<6;j++){
            if(j%2==0){
                ans[i][j] = classRooms[i/2];
                ans[i+1][j] = classRooms[k];
            }
            else{
                ans[i][j] = classRooms[k];
                ans[i+1][j] = classRooms[i/2];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
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