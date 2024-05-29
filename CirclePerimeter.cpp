#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long r;
        cin>>r;
        long long ans = 0;
        for(long long i=1;i<=r;i++){
            long long lowerLimit = 1e6;
            long long low = 0;
            long long high = 1e6;
            while(low<=high){
                long long mid = (low+high)/2;
                if(mid*mid + (i*i) >= r*r){
                    lowerLimit = min(lowerLimit, mid);
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            low = 0;
            high = 1e6;
            long long upperLimit = -1;
            while(low<=high){
                long long mid = (low+high)/2;
                if(mid*mid + (i*i) < (r+1)*(r+1)){
                    upperLimit = max(upperLimit, mid);
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            if(lowerLimit>0){
                ans += (upperLimit-lowerLimit+1)*2;
            }
            else if(lowerLimit==0){
                ans += (upperLimit-lowerLimit)*2 + 1;
            }
        }
        ans *= 2;
        ans += 2;
        cout<<ans<<endl;
    }
}