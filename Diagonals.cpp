#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int temp = n;
        int ans = 0;
        while(k>0){
            if(temp==n){
                k -= temp;
                temp--;
                ans++;
            }
            else{
                k -= temp;
                ans++;
                if(k<=0){
                    break;
                }
                k -= temp;
                ans++;
                temp--;
            }
        }
        cout<<ans<<endl;
    }
}