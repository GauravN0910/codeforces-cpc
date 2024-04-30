#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> nums(n+1);
        vector<long long> prefix(n+1);

        for(int i=1;i<=n;i++){
            cin>>nums[i];
            prefix[i] = prefix[i-1] ^ nums[i];
        }

        vector<long long> left(30);
        vector<long long> right(30);

        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++){
                if((prefix[i]>>j)&1){
                    right[j]++;
                }
            }
        }

        long long ans = 0;

        for(int i=1;i<=n;i++){
            for(int j=0;j<30;j++){
                if((prefix[i-1]>>j)&1){
                    left[j]++;
                    right[j]--;
                }
            }
            int x = __lg(nums[i]);
            ans += left[x]*right[x] + (i-left[x])*(n-i+1-right[x]);
        }
        cout<<ans<<endl;
    }
}