#include<bits/stdc++.h>
using namespace std;

int  main(){
    long long  t;
    cin>>t;
    while(t--){
        long long  n;
        cin>>n;
        vector<long long > a(n);
        vector<long long > b(n+1);

        for(long long  i=0;i<n;i++){
            cin>>a[i];
        }

        for(long long  i=0;i<=n;i++){
            cin>>b[i];
        }

        bool lastFound = false;
        long long  lastElem = b[n];

        long long  ans = 0;
        
        for(long long  i=0;i<n;i++){
            ans += abs(a[i]-b[i]);
        }

        long long k = 1e18;
        for(int i=0;i<n;i++){
            if(lastElem==a[i] || (lastElem<=a[i] && lastElem>=b[i]) || (lastElem>=a[i] && lastElem<=b[i])){
                lastFound = true;
                break;
            }
            k = min({k, abs(lastElem-a[i]), abs(lastElem-b[i])});
        }

        if(lastFound){
            cout<<ans+1<<endl;
        }
        else{
            cout<<ans+k+1<<endl;
        }
    }

}