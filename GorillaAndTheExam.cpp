#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    map<int, int> counts;
    for(auto num:nums){
        counts[num]++;
    }

    vector<int> countVector;
    for(auto elem:counts){
        countVector.push_back(elem.second);
    }

    sort(countVector.begin(), countVector.end());

    int size = countVector.size();
    int idx = 0;
    while(idx<size && k){
        if(countVector[idx]<=k){
            k -= countVector[idx];
            idx++;
        }
        else{
            break;
        }
    }
    if(idx==size){
        cout<<1<<endl;
        return;
    }
    int ans = size - idx;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}