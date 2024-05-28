#include<bits/stdc++.h>
using namespace std;

int sum, blackCount, deg[200010], color[200010], blackChildCount[200010], parent[200010], nodes[200010];
vector<int> graph[200010];
set<int> st;

void dfs(int node){
    for(auto neighbor:graph[node]){
        if(parent[node]==neighbor){
            continue;
        }
        parent[neighbor] = node;
        dfs(neighbor);
    }
}

void updateDeg(int node, int newDeg){
    if(deg[node]==2){
        st.erase(node);
    }
    blackChildCount[deg[node]]--;
    deg[node] = newDeg;
    blackChildCount[deg[node]]++;
    if(deg[node]==2){
        st.insert(node);
    }
}

void turn(int node){
    if(color[node] == 0){
        sum += deg[node];
        blackChildCount[deg[node]]++;
        if(deg[node] == 2){
            st.insert(node);
        }
        if(color[parent[node]]){
            updateDeg(parent[node], deg[parent[node]]+1);
            sum++;
        }
        else{
            deg[parent[node]]++;
        }
        blackCount++;
    }
    else{
        sum -= deg[node];
        blackChildCount[deg[node]]--;
        if(deg[node]==2){
            st.erase(node);
        }
        if(color[parent[node]]){
            updateDeg(parent[node], deg[parent[node]]-1);
            sum--;
        }
        else{
            deg[parent[node]]--;
        }
        blackCount--;
    }
    color[node] ^= 1;
}

bool check(){
    if(blackCount-1 != sum){
        return false;
    }   
    if(blackCount==1){
        return true;
    }
    for(auto x:st){
        if(color[parent[x]]==1){
            return false;
        }
    }

    return (blackChildCount[2] == 1 && blackCount-3 == blackChildCount[1]) || (blackCount-1 == blackChildCount[1]);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;

        blackCount = sum = 0;
        for(int i=1;i<=n;i++){
            st.clear();
            deg[i] = color[i] = blackChildCount[i] = 0;
            graph[i].clear();
        }

        for(int i=1;i<=n;i++){
            cin>>nodes[i];
        }

        for(int i=1;i<n;i++){
            int x, y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        parent[1] = -1;
        dfs(1);

        for(int i=1;i<=n;i++){
            if(nodes[i]==1){
                turn(i);
            }
        }

        while(q--){
            int x;
            cin>>x;
            turn(x);
            cout<<(check() ? "Yes\n":"No\n");
        }
    }
}