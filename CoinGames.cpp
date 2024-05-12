#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int uCount = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='U'){
                uCount++;
            }
        }
        if(uCount%2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}