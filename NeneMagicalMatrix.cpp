#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int sum = (n*(n+1)*(4*n-1))/6;
        cout<<sum<<" "<<2*n<<endl;

        for(int i=0;i<2*n;i++){
            cout<<(i%2)+1<<" "<<n-(i/2)<<" ";
            for(int j=1;j<=n;j++){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
}