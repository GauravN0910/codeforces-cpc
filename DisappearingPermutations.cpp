#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n+1);
    map<int, int> numToIdx;

    for(int i=1;i<=n;i++){
        cin>>nums[i];
        numToIdx[nums[i]] = i;
    }

    set<int> visited;

    for(int i=0;i<n;i++){
        int pos;
        cin>>pos;
        nums[pos] = 0;
        if(visited.find(pos)==visited.end()){
            int curPos = pos;
            while(visited.find(curPos)==visited.end()){
                visited.insert(curPos);
                curPos = numToIdx[curPos];
            }
        }
        cout<<visited.size()<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}