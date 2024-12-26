#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, m, q;
    cin>>n>>m>>q;

    vector<pair<int, int>> intervals;
    intervals.push_back({m, m});

    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        vector<pair<int, int>> nextLevel;
        for(auto [start, end]:intervals){
            if(start>x){
                nextLevel.push_back({start-1, end});
                continue;
            }
            if(x>end){
                nextLevel.push_back({start, end+1});
                continue;
            }
            nextLevel.push_back({1, 1});
            nextLevel.push_back({n, n});
            if(start==x && end==x){
                continue;
            }
            nextLevel.push_back({start, end});
        }

        sort(nextLevel.begin(), nextLevel.end());
        vector<pair<int, int>> merged;
        for(auto [start, end]:nextLevel){
            if(merged.empty()){
                merged.push_back({start, end});
                continue;
            }

            int prevStart = merged.back().first;
            int prevEnd = merged.back().second;
            merged.pop_back();

            if(prevEnd>=start-1){
                merged.push_back({prevStart, max(prevEnd, end)});
            }
            else{
                merged.push_back({prevStart, prevEnd});
                merged.push_back({start, end});
            }
        }

        intervals = merged;
        int ans = 0;
        for(auto [start, end]:merged){
            ans += end - start + 1;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}