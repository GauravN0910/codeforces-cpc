#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    vector<int> minSoFar(n);
    minSoFar[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--){
        minSoFar[i] = min(nums[i], minSoFar[i+1]);
    }
    
    int lastNum = nums[n-1];
    vector<int> changeFactor(n);

    for(int i=0;i<n-1;i++){
        if(nums[i]>lastNum){
            changeFactor[i]=1;
        }
        else if(nums[i]<=minSoFar[i+1]){
            continue;
        }
        else if(nums[i]>minSoFar[i+1]){
            changeFactor[i] = 1;
        }
    }

    int maxNum = INT_MIN;
    for(int i=0;i<n-1;i++){
        nums[i] += changeFactor[i];
        maxNum = max(maxNum, nums[i]);
    }

    if(maxNum<lastNum){
        nums[n-1]++;
    }

    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}