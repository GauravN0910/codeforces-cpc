#include<bits/stdc++.h>
using namespace std;

int mods[400005];

int main(){
    int k = 0;
    int q, x;
    cin>>q>>x;
    while(q--){
        int n;
        cin>>n;
        mods[n%x]++;
        while(mods[k%x]>k/x){
            k++;
        }
        cout<<k<<endl;
    }
}