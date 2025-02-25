#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool isNewNumsMagical(vector<int>& nums){
    int n = nums.size();
    vector<int> prefixMin(n);
    vector<int> suffixMex(n);
    prefixMin[0] = nums[0];
    for(int i=1;i<n;i++){
        prefixMin[i] = min(prefixMin[i-1], nums[i]);
    }
    int mex = 0;
    set<int> usedNums;
    for(int i=n-1;i>=0;i--){
        usedNums.insert(nums[i]);
        while(usedNums.find(mex)!=usedNums.end()){
            mex++;
        }
        suffixMex[i] = mex;
    }

    for(int i=0;i<n-1;i++){
        if(prefixMin[i]<suffixMex[i+1]){
            return false;
        }
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int flag = true;
    int zeroCount = 0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i]==0){
            flag = false;
            zeroCount++;
        }
    }
    if(flag){
        cout<<n<<endl;
        return;
    }

    int ans = n - zeroCount;
    vector<int> newNums;
    bool zeroEncountered = false;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            if(!zeroEncountered){
                zeroEncountered = true;
                newNums.push_back(nums[i]);
            }
        }
        else{
            newNums.push_back(nums[i]);
        }
    }

    if(isNewNumsMagical(newNums)){
        ans += 1;
        cout<<ans<<endl;
        return;
    }
    else{
        cout<<ans<<endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}