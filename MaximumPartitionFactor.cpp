#include<bits/stdc++.h>
using namespace std;

bool helper(vector<vector<long long>>& points, long long mid){
    long long n = points.size();
    vector<vector<long long>> adj(n, vector<long long>());

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((abs(points[i][0] - points[j][0])+abs(points[i][1]-points[j][1]))<=mid){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> color(n, -1);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int x = q.front();
                q.pop();

                for(auto y:adj[x]){
                    if(color[y]==-1){
                        color[y] = !color[x];
                        q.push(y);
                    }
                    else if(color[x]==color[y]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    long long n;
    cin>>n;
    vector<vector<long long>> points(n);
    for(long long i=0;i<n;i++){
        long long x, y;
        cin>>x>>y;
        points[i] = {x, y};
    }

    long long low = 0;
    long long high = 1e9;
    while(low<=high){
        long long mid = low + (high-low)/2;
        if(helper(points, mid)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<low<<endl;
}