#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n, m;
    cin>>n>>m;
    vector<long long> prices(n);
    vector<long long> quantities(n);

    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    for(int i=0;i<n;i++){
        cin>>quantities[i];
    }

    map<long long, long long> count;
    for(int i=0;i<n;i++){
        count[prices[i]] = quantities[i];
    }

    long long ans = 0;      
    for(auto elem:count){
        long long price = elem.first;
        long long quantity = elem.second;

        long long nextQuantity = 0;

        if(count.find(price + 1)!=count.end()){
            nextQuantity = count[price + 1];
        }

        long long case1 = min(quantity, m/price);
        long long remainingBudget =  m - case1 * price;
        long long case2 = 0;
        if(nextQuantity>0){
            case2 = min(nextQuantity, remainingBudget/(price+1));
            remainingBudget -= case2 * (price+1);
        }

        ans = max(ans, case1 * price + case2 * (price+1));
        long long remainingNext = nextQuantity - case2;
        long long budget = remainingBudget;

        long long canRemove = min({case1, budget, remainingNext});
        case1 -= canRemove;
        case2 += canRemove;

        ans = max(ans, case1 * price + case2 * (price+1));
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}