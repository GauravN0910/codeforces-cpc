#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        sort(a.begin(), a.end());
        int j = 0;
        int i;
        for(i=1;i<n;i++){
            if(a[i]%a[0]){
                if(j){
                    if(a[i]%a[j]){
                        break;
                    }
                }
                else{
                    j = i;
                }
            }
        }
        if(i>=n){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}