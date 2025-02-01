#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

vector<long long> buildArray(vector<long long>& nums){
    long long n = nums.size();
    vector<long long> ans;
    for(long long i=1;i<n;i++){
        ans.push_back(nums[i] - nums[i-1]);
    }
    return ans;
}
void solve(){
    long long n;
    cin>>n;
    vector<long long> nums;
    long long sum = 0;
    for(long long i=0;i<n;i++){
        long long x;
        cin>>x;
        nums.push_back(x);
        sum += x;
    }

    

    long long ans = sum;
    while(true){
        if(nums.size()==1){
            break;
        }
        vector<long long> newNums = buildArray(nums);
        long long newSum = 0;
        for(auto x:newNums){
            newSum += x;
        }

        if(2*newSum>0){
            nums = newNums;
            ans = max(ans, newSum);
        }
        else{
            ans = max(ans, -1*newSum);
            reverse(nums.begin(), nums.end());
            nums = buildArray(nums);
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}