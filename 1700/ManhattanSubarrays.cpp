#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool checkFn(vector<int>& nums, int x, int y){
    for(int i=x;i<=y;i++){
        for(int j=i+1;j<=y;j++){
            for(int k=j+1;k<=y;k++){
                if((nums[i]<=nums[j] && nums[j]<=nums[k]) || (nums[i]>=nums[j] && nums[j]>=nums[k])){
                    return false;
                }
            }
        }
    }
    return true;

}

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j-i+1<=2){
                ans++;
            }
            else if(j-i+1>=5){
                break;
            }
            else{
                bool flag = checkFn(nums, i, j);
                if(flag){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}