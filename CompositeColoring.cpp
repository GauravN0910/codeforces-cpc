#include<bits/stdc++.h>
using namespace std;

map<int, int> x = {{2,1}, {3,2}, {5,3}, {7,4}, {11,5}, {13, 6}, {17,7}, {19,8}, {23,9}, {29,10}, {31,11}};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        vector<int> visited(12);
        for(int i=0;i<n;i++){
            for(auto elem:x){
                if(nums[i]%elem.first==0){
                    visited[elem.second] = 1;
                    break;
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=11;i++){
            if(visited[i]){
                ans++;
            }
        }

        map<int, int> y;
        int pos = 1;
        for(int i=1;i<=11;i++){
            if(visited[i]){
                y[i] = pos;
                pos++;
            }
        }

        cout<<ans<<endl;

        for(int i=0;i<n;i++){
            for(auto elem:x){
                if(nums[i]%elem.first==0){
                    cout<<y[elem.second]<<" ";
                    break;
                }
            }
        }
        cout<<endl;
    }
}