#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool isNonDecreasing(vector<int> &nums){
    for(int i=1;i<nums.size();i++){
        if(nums[i] < nums[i-1]){
            return false;
        }
    }
    return true;
}

int calculateMex(vector<int> &nums){
    set<int> uniqueElements;
    for(auto x: nums){
        uniqueElements.insert(x);
    }
    int mex = 0;
    for(auto x: uniqueElements){
        if(x==mex){
            mex++;
        }
        else{
            break;
        }
    }
    return mex;
}

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int> ansIdx;

    while(!isNonDecreasing(nums)){
        int mex = calculateMex(nums);
        if(mex<n){
            nums[mex] = mex;
            ansIdx.push_back(mex+1);
        }
        else{
            int idx = 0;
            while(nums[idx]==idx){
                idx++;
            }
            nums[idx] = mex;
            ansIdx.push_back(idx+1);
        }
    }

    cout<<ansIdx.size()<<endl;
    for(auto x:ansIdx){
        cout<<x<<" ";
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