#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> colors(n);
    map<int, int> usedColors;
    map<int, int> usedByAlice;
    for(int i=0;i<n;i++){
        cin>>colors[i];
    }

    map<int, int> map;
    for(int i=0;i<n;i++){
        map[colors[i]]++;
    }   

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto elem:map){
        pq.push({elem.second, elem.first});
    }

    int player = 1;
    int aliceScore = 0;

    while(!pq.empty()){
        pair<int, int> color = pq.top();
        pq.pop();
            
        
        if(player==1 && !usedByAlice.count(color.second)){
            aliceScore++;
            if(!usedColors.count(color.second) && color.first==1){
                aliceScore++;
            }
            usedByAlice[color.second]=1;
            player = 2;
        }
        else{
            player = 1;
        }

        if(color.first>1){
            pq.push({color.first-1, color.second});
        }
        usedColors[color.second]=1;
    }

    cout<<aliceScore<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}