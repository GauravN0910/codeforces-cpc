#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int sum = 0;
    vector<int> stones(n);
    for(int i=0;i<n;i++){
        cin>>stones[i];
        sum += stones[i];
    }

    map<int, set<int>> map;
    for(int i=0;i<n;i++){
        map[stones[i]].insert(i);
    }

    vector<pair<int, int>> moves;

    int i=n-1;
    while(i>=0){
        if(stones[i]==2){
            map[2].erase(map[2].find(i));
            i--;
            continue;
        }
        else if(stones[i]==1){
            if(!map[2].empty()){
                int x = *map[2].begin();
                map[2].erase(map[2].find(x));
                moves.push_back({x, i});
                map[1].insert(x);
                map[1].erase(map[1].find(i));
                stones[x]--;
                stones[i]++;
                i--;
            }
            else{
                map[1].erase(map[1].find(i));
                i--;
            }
            
        }
        else if(stones[i]==0){
            if(!map[1].empty()){
                int x = *map[1].begin();
                map[1].erase(map[1].find(x));
                moves.push_back({x, i});
                map[0].insert(x);
                map[1].insert(i);
                map[0].erase(map[0].find(i));
                stones[x]--;
                stones[i]++;
            }
            else{
                map[0].erase(map[0].find(i));
                i--;
            }
        }
    }

    cout<<moves.size()<<endl;
    for(auto [x, y]:moves){
        cout<<x+1<<" "<<y+1<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}