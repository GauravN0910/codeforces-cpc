#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool isValley(vector<int>& nums, int idx){
    return (idx>0 && idx<nums.size()-1 && nums[idx]<nums[idx+1] && nums[idx]<nums[idx-1]);
}

bool isHill(vector<int>& nums, int idx){
    return (idx>0 && idx<nums.size()-1 && nums[idx]>nums[idx+1] && nums[idx]>nums[idx-1]);
}

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int sum = 0;
    vector<int> valleyOrHill(n);
    for(int i=1;i<n-1;i++){
        if(isValley(nums, i) || isHill(nums, i)){
            valleyOrHill[i] = 1;
            sum++;
        }
    }

    int ans = sum;

    for(int i=1;i<n-1;i++){
        int temp = nums[i];
        nums[i] = nums[i-1];
        ans = min(ans, sum - valleyOrHill[i-1] - valleyOrHill[i] - valleyOrHill[i+1] + isValley(nums, i-1) 
        + isValley(nums, i) + isValley(nums, i+1) + isHill(nums, i-1) + isHill(nums, i) + isHill(nums, i+1));

        nums[i] = nums[i+1];
        ans = min(ans, sum - valleyOrHill[i-1] - valleyOrHill[i] - valleyOrHill[i+1] + isValley(nums, i-1) 
        + isValley(nums, i) + isValley(nums, i+1) + isHill(nums, i-1) + isHill(nums, i) + isHill(nums, i+1));

        nums[i] = temp;
    }

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