#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if(m>n){
            cout<<"No"<<endl;
        }
        else if(m==n){
            cout<<"Yes"<<endl;
        }
        else{
            if((n-m)%2==0){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
}