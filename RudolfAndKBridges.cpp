#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n, m, k, d;
        cin>>n>>m>>k>>d;
        d++;

        vector<vector<long long>> depths(n, vector<long long>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>depths[i][j];
            }
        }

        long long dp[n][m];
 
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j ++ )
            {
                dp[i][j] = 1e18;
            }
            
            dp[i][m-1] = depths[i][m-1] + 1;
        }

        vector<long long> costs(n);

        for(int i=0;i<n;i++){
            multiset<long long> ms;
            ms.insert(dp[i][m-1]);
            for(int j=m-2;j>=0;j--){
                if(ms.size()>d){
                    ms.erase(ms.find(dp[i][j+d+1]));
                }
                dp[i][j] = depths[i][j] + 1 + *(ms.begin());
                ms.insert(dp[i][j]);
            }
            costs[i] = dp[i][0];
        }

        long long ans = 1e18;
        long long temp = 0;
        for(int i=0;i<k-1;i++){
            temp += costs[i];
        }

        for(int i=k-1;i<n;i++){
            temp += costs[i];
            ans = min(ans, temp);
            temp -= costs[i-k+1];
        }
        cout<<ans<<endl;
    }
}