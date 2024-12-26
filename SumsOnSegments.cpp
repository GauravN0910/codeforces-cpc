#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n+1);
    int idxOfX = 0;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        if(nums[i]!=1 && nums[i]!=-1){
            idxOfX = i;
        }
    }

    set<int> subarraySums;
    subarraySums.insert(0);

    int sum = 0;
    int minSumLeft = 0;
    int maxSumLeft = 0;
    int leftLimit = 0;
    int rightLimit = 0;
    for(int i=1;i<idxOfX;i++){
        sum += nums[i];
        leftLimit = min(leftLimit, sum - maxSumLeft);
        rightLimit = max(rightLimit, sum - minSumLeft);
        maxSumLeft = max(maxSumLeft, sum);
        minSumLeft = min(minSumLeft, sum);
    }

    for(int val=leftLimit;val<=rightLimit;val++){
        subarraySums.insert(val);
    }

    sum = 0;
    int minSumRight = 0;
    int maxSumRight = 0;
    leftLimit = 0;
    rightLimit = 0;
    for(int i=n;i>idxOfX;i--){
        sum += nums[i];
        leftLimit = min(leftLimit, sum - maxSumRight);
        rightLimit = max(rightLimit, sum - minSumRight);
        maxSumRight = max(maxSumRight, sum);
        minSumRight = min(minSumRight, sum);
    }

    for(int val=leftLimit;val<=rightLimit;val++){
        subarraySums.insert(val);
    }


    int L1 = 0, R1 = 0;
    int L2 = 0, R2 = 0;
    for(int i=1;i<idxOfX;i++){
        L1 += nums[i];
        R1 += nums[i];
        if(L1>0){
            L1 = 0;
        }
        if(R1<0){
            R1 = 0;
        }
    }

    for(int i=n;i>idxOfX;i--){
        L2 += nums[i];
        R2 += nums[i];
        if(L2>0){
            L2 = 0;
        }
        if(R2<0){
            R2 = 0;
        }
    }

    int leftMax = L1 + L2 + nums[idxOfX];
    int rightMax = R1 + R2 + nums[idxOfX];

    for(int val=leftMax;val<=rightMax;val++){
        subarraySums.insert(val);
    }

    cout<<subarraySums.size()<<endl;
    for(auto val:subarraySums){
        cout<<val<<" ";
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