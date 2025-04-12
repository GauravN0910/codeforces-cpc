#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n, m;
    cin>>n>>m;
    vector<long long> centres(n);
    vector<long long> radius(n);
    for(long long i=0;i<n;i++){
        cin>>centres[i];
    }
    for(long long i=0;i<n;i++){
        cin>>radius[i];
    }

    map<long long, long long> map;
    for(long long i=0;i<n;i++){
        long long leftLimit = centres[i] - radius[i];
        long long rightLimit = centres[i] + radius[i];
        for(long long xCoord=leftLimit;xCoord<=rightLimit;xCoord++){
            long long xDistance = xCoord - centres[i];
            long long yDistance = radius[i]*radius[i] - xDistance*xDistance;
            long long yCoord = sqrt(yDistance);
            if(map.count(xCoord)){
                if(map[xCoord]<yCoord){
                    map[xCoord] = yCoord;
                }
            }
            else{
                map[xCoord] = yCoord;
            }
        }
    }

    long long ans = 0;
    for(auto elem:map){
        ans += 2*elem.second + 1;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}