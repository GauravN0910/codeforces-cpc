#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        for(int i=1;i<n-1;i++){
            if(nums[i]<  2*nums[i-1]){
                break;
            }
            else{
                nums[i] = nums[i] - 2*(nums[i-1]);
                nums[i+1] = nums[i+1] - nums[i-1];
                nums[i-1] = 0;
            }
        }

        bool flag = true;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                flag = false;
                break;
            }
        }

        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}