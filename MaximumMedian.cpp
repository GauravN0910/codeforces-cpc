#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    long long ans = nums[n/2];
    long long low = 0;
    long long high = 1e18 + 90;
    while(low<=high){
        long long mid = low + (high-low)/2;
        long long sum = 0;
        for(int i=n/2;i<n;i++){
            if(nums[i]<=mid){
                sum += (mid-nums[i]);
            }
            if(sum>k){
                break;
            }
        }

        if(sum<=k){
            ans = max(ans, mid);
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
    cout << ans << endl;
}