#include<bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>>& graph, vector<int>& nums){
    int minSub = INT_MAX;
    for(auto neighbor:graph[node]){
        minSub = min(minSub, dfs(neighbor, graph, nums));
    }

    if(minSub==INT_MAX){
        return nums[node];
    }
    if(node==1){
        return nums[node] + minSub;
    }
    return nums[node]>=minSub?minSub:(nums[node]+minSub)/2;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> graph(n+1, vector<int>());
        vector<int> nums(n+1);
        for(int i=1;i<=n;i++){
            cin>>nums[i];
        }

        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            graph[x].push_back(i);
        }

        int ans = dfs(1, graph, nums);
        cout<<ans<<endl;
    }
}