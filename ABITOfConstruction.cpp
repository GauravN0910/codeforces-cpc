#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        if(n==1){
            cout<<k;
        }
        else{
            int numSetBits = log2(k);
            int firstNum = (1<<numSetBits) - 1;
            cout<<firstNum<<" ";
            cout<<k-firstNum<<" ";
            for(int i=0;i<n-2;i++){
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}