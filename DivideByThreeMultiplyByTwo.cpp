#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    set<pair<long long, long long>> set;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        long long tempX = x;
        long long powerOf3 = 0;
        while(tempX%3==0){
            powerOf3++;
            tempX = tempX/3;
        }
        set.insert({-powerOf3, x});
    }

    for(auto [x, y]:set){
        cout<<y<<" ";
    }
}