#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans = 0;
        int a = INT_MAX;
        int b = INT_MAX;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(a>=x){
                a=x;
            }
            else if(b>=x){
                b=x;
            }
            else{
                a=b;
                b=x;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}