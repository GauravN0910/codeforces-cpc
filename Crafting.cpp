#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    vector<int> difference(n);
    for(int i=0;i<n;i++){
        difference[i] = a[i] - b[i];
    }

    int negCount = 0;
    for(int i=0;i<n;i++){
        if(difference[i]<0){
            negCount++;
        }
    }

    if(negCount>=2){
        cout<<"NO"<<endl;
        return;
    }

    if(negCount==0){
        cout<<"YES"<<endl;
        return;
    }

    int negNum = 0;
    for(int i=0;i<n;i++){
        if(difference[i]<0){
            negNum = abs(difference[i]);
            break;
        }
    }

    bool flag = true;
    for(int i=0;i<n;i++){
        if(difference[i]>=0 && difference[i]<negNum){
            flag = false;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
        return;
    }
    else{
        cout<<"NO"<<endl;
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