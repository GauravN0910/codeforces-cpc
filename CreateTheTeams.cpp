#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());
        int ans = 0;
        int subArrSize = 1;
        for(int i=n-1;i>=0;i--){
            if(subArrSize * nums[i] >=x){
                ans++;
                subArrSize = 0;
            }
            subArrSize++;
        }

        cout<<ans<<endl;
    }
}