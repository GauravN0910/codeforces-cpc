#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

void solve(){
    int left, right;  
    cin >> left >> right;  
    int sum = 0;  
    int misMatchIdx = 31; 

    while (misMatchIdx >= 0) {  
        if ((left & (1ll << misMatchIdx)) == (right & (1ll << misMatchIdx))) {  
            if (left & (1ll << misMatchIdx)){
                sum += (1ll << misMatchIdx);  
            }
        }
        else{
            break;
        }
        misMatchIdx -= 1;
    }  

    cout<<sum + (1LL<<misMatchIdx) - 1<<" "<<sum + (1LL<<misMatchIdx)<<" ";

    if (right > sum + (1ll << misMatchIdx)) {  
        cout<<sum + (1ll << misMatchIdx) + 1<<endl;
    }
    else {  
        cout<< sum + (1ll << misMatchIdx) - 2<<endl;
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

