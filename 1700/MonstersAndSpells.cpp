#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    long long n;
    cin>>n;

    vector<long long> timeOfArrival(n);
    vector<long long> health(n);
    for(long long i=0;i<n;i++){
        cin>>timeOfArrival[i];
    }
    for(long long i=0;i<n;i++){
        cin>>health[i];
    }

    long long ans = 0;

    long long lastTime = timeOfArrival[n-1];
    long long lastHealth = health[n-1];
    long long maxHealth = health[n-1];
    long long maxHealthTime = timeOfArrival[n-1];

    for(long long i=n-2;i>=0;i--){
        if(lastTime - timeOfArrival[i]>=lastHealth){
            ans += maxHealth*(maxHealth+1)/2;
            maxHealth = health[i];
            maxHealthTime = timeOfArrival[i];
            lastTime = timeOfArrival[i];
            lastHealth = health[i];
        }
        else if(lastTime - timeOfArrival[i] <= lastHealth - health[i]){
            continue;
        }
        else{
            maxHealth = health[i] + maxHealthTime - timeOfArrival[i];
            lastHealth = health[i];
            lastTime = timeOfArrival[i];
        }
    }
    ans += maxHealth*(maxHealth+1)/2;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}