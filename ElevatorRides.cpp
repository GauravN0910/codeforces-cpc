#include<bits/stdc++.h>
using namespace std;

pair<int, int> dp[1<<20];
int main(){
    int n, x;
    cin>>n>>x;
    vector<int> weights(n);
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }

    dp[0] = {0, x};

    for(int mask = 1; mask<(1<<n); mask++){
        dp[mask] = {n+1, 0};
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                auto option = dp[mask^(1<<i)];
                if(option.second + weights[i]<=x){
                    option.second += weights[i];
                } 
                else{
                    option.first++;
                    option.second = weights[i];
                }
                dp[mask] = min(dp[mask], option);
            }
        }
    }
    int ans = dp[(1<<n)-1].first;
    cout<<ans<<endl;
}