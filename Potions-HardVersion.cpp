#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> potions(n);
    long long ans = 0;
    long long sum = 0;
    for(long long i=0;i<n;i++){
        cin>>potions[i];
    }

    priority_queue<long long> pq;

    for(long long i=0;i<n;i++){
        if(potions[i]>=0){
            sum += potions[i];
            ans++;
        }
        else{
            if(sum + potions[i] >= 0){
                sum += potions[i];
                ans++;
                pq.push(-potions[i]);
            }
            else{
                if(pq.empty()) continue;
                long long top = pq.top();
                if(top>abs(potions[i])){
                    sum += top;
                    pq.pop();
                    sum += potions[i];
                    pq.push(-potions[i]);
                }
            }
        }
    }
    
    cout<<ans<<endl;
}