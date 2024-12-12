#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    string n;
    cin>>n;
    int sz = n.size();

    int sumNums = 0;
    int twoCount = 0;
    int threeCount = 0;
    for(int i=0;i<sz;i++){
        sumNums += n[i]-'0';
        if(n[i]-'0'==2){
            twoCount++;
        }
        if(n[i]-'0'==3){
            threeCount++;
        }
    }

    int modVal = sumNums%9;
    if(modVal==0){
        cout<<"YES"<<endl;
        return;
    }

    int remaining = 9-modVal;

    if(remaining==1){
        if((threeCount && twoCount>=2) || twoCount>=5){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }
    
    if(remaining==2){
        if(twoCount){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }

    if(remaining==3){
        if(threeCount>=2 || twoCount>=6 || (threeCount && twoCount>=3)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }

    if(remaining==4){
        if(twoCount>=2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }

    if(remaining==5){
        if((threeCount>=2 && twoCount) || (twoCount>=7) || (threeCount && twoCount>=4)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }

    if(remaining==6){
        if(twoCount>=3 || threeCount){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }

    if(remaining==7){
        if(twoCount>=8 || (threeCount>=2 && twoCount>=2) || (threeCount && twoCount>=5)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }

    if(remaining==8){
        if(twoCount>=4 || (twoCount && threeCount)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}