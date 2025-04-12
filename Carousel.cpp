#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> types(n);
    for(int i=0;i<n;i++){
        cin>>types[i];
    }

    int count = 0;
    for(int i=0;i<n;i++){
        if(types[i] == types[0]){
            count++;
        }
    }

    if(count == n){
        cout<<1<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }

    if(n%2==0){
        cout<<2<<endl;
        for(int i=0;i<n;i++){
            cout<<i%2+1<<" ";
        }
        cout<<endl;
        return;
    }

    bool flag = false;
    int idx = -1;
    for(int i=0;i<n;i++){
        if(types[i] == types[(i+1)%n]){
            flag = true;
            idx = i;
            break;
        }
    }

    if(flag){
        cout<<2<<endl;
        bool colorSwitch = false;
        for(int i=0;i<n;i++){
            int color;
            if(!colorSwitch){
                color = i%2 + 1;
            }
            else{
                color = (i+1)%2 + 1;
            }

            if(i == idx){
                cout<<color<<" ";
                if(i!=n-1){
                    cout<<color<<" ";
                    i++;
                }
                colorSwitch = !colorSwitch;
            }
            else{
                cout<<color<<" ";
            }
        }
        cout<<endl;
        return;
    }

    else{
        cout<<3<<endl;
        for(int i=0;i<n-1;i++){
            cout<<i%2+1<<" ";
        }
        cout<<3<<" ";
        cout<<endl;
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