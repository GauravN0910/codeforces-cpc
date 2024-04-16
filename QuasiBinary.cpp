#include<bits/stdc++.h>
using namespace std;

int x[101];

int main(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i=1;i<=n;i*=10){
        ans = max(ans, ((n/i)%10));
        for(int j=1;j<=((n/i)%10);j++){
            x[j]+=i;
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++){
        cout<<x[i]<<" ";
    }


}