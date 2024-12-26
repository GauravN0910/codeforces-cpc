#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long hot, cold, temp;
    cin>>hot>>cold>>temp;

    double avgTemp = (hot + cold)/2;

    if(temp<=avgTemp){
        cout<<2<<endl;
        return;
    }    
    else{
        long long x = (temp - hot)/(hot + cold - 2*temp);
        long long y = x + 1;

        double tempX = (double)(hot + x*(hot + cold))/(2*x + 1);
        double tempY = (double)(hot + y*(hot + cold))/(2*y + 1);

        double diffX = abs(temp - tempX);
        double diffY = abs(temp - tempY);
        
        if(diffX<=diffY){
            cout<<2*x + 1<<endl;
        }
        else{
            cout<<2*y + 1<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}