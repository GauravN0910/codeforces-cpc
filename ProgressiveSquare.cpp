#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c, d;
        cin>>n>>c>>d;
        vector<int> arr(n*n);
        for(int i=0;i<n*n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(), arr.end());
        vector<vector<int>> nums(n, vector<int>(n));

        vector<int> sorted;

        nums[0][0] = arr[0];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    sorted.push_back(nums[i][j]);
                    continue;
                }
                else if(i==0){
                    nums[i][j] = nums[i][j-1] + d;
                }
                else if(j==0){
                    nums[i][j] = nums[i-1][j] + c;
                }
                else{
                    nums[i][j] = nums[i][j-1] + d;
                }
                sorted.push_back(nums[i][j]);
            }
        }

        sort(sorted.begin(), sorted.end());
        
        if(arr==sorted){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}