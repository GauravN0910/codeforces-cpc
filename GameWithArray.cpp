#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin>>n>>s;

    int rem = s/n;
    if(rem==1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<n-1;i++){
            cout<<rem<<" ";
        }
        int last = s - (n-1)*rem;
        cout<<last<<endl;
        cout<<1<<endl;
    }
}