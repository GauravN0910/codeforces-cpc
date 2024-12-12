#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    long long sum=0;
    long long oddSum=0, evenSum=0;
    long long oddCount=(n+1)/2;
    long long evenCount= n - oddCount;
    
    for(long long i=0;i<n;i++){
        sum +=nums[i];
        if((i+1)%2){
            oddSum += nums[i];
        }
        else{
            evenSum += nums[i];
        }
    }
    if(sum%n){
        cout<<"NO"<<endl;
        return;
    }
    
    long long changedNum = sum/n;
    if((oddSum == changedNum * oddCount) && (evenSum == changedNum * evenCount)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}