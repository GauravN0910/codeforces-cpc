#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool helperFn(multiset<int>& set, int maxNum, vector<pair<int, int>>& ans, int n){
    while(!set.empty()){
        int sum = maxNum;
        maxNum = *set.rbegin();
        set.erase(set.find(maxNum));
        if(set.find(sum - maxNum) == set.end()){
            break;
        }
        else{
            set.erase(set.find(sum - maxNum));
            ans.push_back({maxNum, sum - maxNum});
        }
    }

    if(ans.size() == n/2){
        cout<<"YES"<<endl;
        cout<<ans[0].first + ans[0].second<<endl;
        for(auto [x, y]:ans){
            cout<<x<<" "<<y<<endl;
        }
        return true;
    }
    return false;
}

void solve(){
    int n;
    cin>>n;
    n *= 2;
    vector<int> nums(n);
    multiset<int> set;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        set.insert(nums[i]);
    }

    sort(nums.begin(), nums.end());
    int idx = 0;
    vector<pair<int, int>> ans;
    for(int i=0;i<n-1;i++){
        ans.push_back({nums[i], nums[n-1]});
        multiset<int> dupSet(set);
        dupSet.erase(dupSet.find(nums[i]));
        dupSet.erase(dupSet.find(nums[n-1]));
        if(helperFn(dupSet, nums[n-1], ans, n)){
            return;
        }
        ans.clear();
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}