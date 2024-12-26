#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long l, r, G;
    cin>>l>>r>>G;

    long long lx = ((l+G-1)/G)*G;
    long long rx = (r/G)*G;

    pair<long long, long long> ans = {-1, -1};
    long long distance = -1;

    set<long long> multiples;
    for(long long i=0;i<100;i++){
        if(lx+G*i <= r && lx+G*i >= l){
            multiples.insert(lx + G*i);
        }
    }

    for(long long i=0;i<100;i++){
        if(rx-G*i <= r && rx-G*i >= l){
            multiples.insert(rx - G*i);
        }
    }

    for(long long x:multiples){
        for(long long y:multiples){
            if(y>=x && y-x>distance){
                if(__gcd(x, y)==G){
                    distance = y-x;
                    ans = {x, y};
                }
            }
        }
    }

    cout<<ans.first<<" "<<ans.second<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}