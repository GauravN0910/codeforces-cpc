#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int ask(int x, int y, int z){
    cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
    int ans;
    cin>>ans;
    if(ans==-1){
        exit(0);
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;

    if(n==3){
        cout<<"! "<<1<<" "<<2<<" "<<3<<endl;
        return;
    }

    int count = 0;
    queue<vector<int>> q;
    q.push({1, 2, 3});
    while(count<75 && !q.empty()){
        vector<int> front = q.front();
        q.pop();
        int x = front[0];
        int y = front[1];
        int z = front[2];
        count++;
        int ans = ask(x, y, z);
        if(ans==0){
            cout<<"! "<<x<<" "<<y<<" "<<z<<endl;
            return;
        }
        else{
            q.push({x, y, ans});
            q.push({x, z, ans});
            q.push({y, z, ans});
        }
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