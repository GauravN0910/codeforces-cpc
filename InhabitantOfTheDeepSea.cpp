#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        vector<long long> ships(n);
        for(long long i=0;i<n;i++){
            cin>>ships[i];
        }

        long long ans = 0;
        long long x = k-k/2;
        long long y = k/2;

        for(long long i=0;i<n;i++){
            if(ships[i]<=x){
                ans++;
                x = x-ships[i];
                ships[i] = 0;
            }
            else{
                ships[i] -= x;
                break;
            }
        }

        for(long long i=n-1;i>=0;i--){
            if(ships[i]==0){
                break;
            }
            if(ships[i]<=y){
                ans++;
                y = y-ships[i];
                ships[i]=0;
            }
            else{
                break;
            }
        }
        cout<<ans<<endl;
    }
}