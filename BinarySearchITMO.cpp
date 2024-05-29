#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());

    int k;
    cin>>k;
    while(k--){
        int l, r;
        cin>>l>>r;
        int lowerBound;
        int low = -1;
        int high = n;
        while(low+1<high){
            int mid = low + (high-low)/2;
            if(nums[mid]<l){
                low = mid;
            }
            else{
                high = mid;
            }
        }

        lowerBound = high+1;

        int upperBound;
        low = -1;
        high = n;
        while(low+1<high){
            int mid = low + (high-low)/2;
            if(nums[mid]<=r){
                low = mid;
            }
            else{
                high = mid;
            }
        }

        upperBound = low+1;

        cout<<upperBound-lowerBound+1<<endl;
    }
}