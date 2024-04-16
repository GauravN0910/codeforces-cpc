#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string hashes = "##";
        string dots = "..";
        int count = 0;
        for(int i=0;i<2*n;i++){
            for(int j=0;j<n;j++){
                if(count==0 || count==1){
                    if(j%2==0){
                        cout<<hashes;
                    }
                    else{
                        cout<<dots;
                    }
                }
                else{
                    if(j%2==0){
                        cout<<dots;
                    }
                    else{
                        cout<<hashes;
                    }
                }
            }
            count = (count+1)%4;
            cout<<endl;
        }
    }
}