#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> nums;
    long long product = 1;
    long long ans = 0;

    for(long long i=1;i<n;i++){
        if(__gcd(i, n)==1){
            nums.push_back(i);
            product *= i;
            product %= n;
            ans++;
        }
    }

    if(product!=1){
        for(long long i=0;i<nums.size();i++){
            if((nums[i]*(n-1))%n==1){
                nums[i] = -1;
                ans--;
                break;
            }
        }
    }

    cout<<ans<<endl;
    for(auto num:nums){
        if(num!=-1){
            cout<<num<<" ";
        }
    }
    cout<<endl;
}