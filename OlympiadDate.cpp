#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;


void solve(){
    int n;
    cin>>n;
    
    map<int, int> count;
    count[0] = 3;
    count[1] = 1;
    count[2] = 2;
    count[3] = 1;
    count[5] = 1;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int ans = 0;
    
    for(int i=0;i<n;i++){
        ans++;
        int num = nums[i];
        if(count.find(num)!=count.end()){
            count[num]--;
            if(count[num]==0){
                count.erase(num);
            }
        }
        if(count.empty()){
            break;
        } 
    }

    if(count.empty()){
        cout<<ans<<endl;
        return;
    }
    else{
        cout<<0<<endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}