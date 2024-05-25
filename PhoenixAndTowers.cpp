#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, x;
        cin>>n>>m>>x;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> nums(n);
        for(int i=1;i<=m;i++){
            pq.push({0, i});
        }

        cout<<"YES"<<endl;

        for(int i=0;i<n;i++){
            int y;
            cin>>y;
            int towerNumber = pq.top().second;
            int towerHeight = pq.top().first;
            pq.pop();
            cout<<towerNumber<<" ";
            towerHeight += y;
            pq.push({towerHeight, towerNumber});
        }  
        cout<<endl;
    }
}