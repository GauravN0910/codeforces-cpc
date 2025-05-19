#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int ask(int left, int right){
    if(left>=right){
        return -1;
    }
    cout<<"?"<<" "<<left<<" "<<right<<endl;
    int x;
    cin>>x;
    return x;

}

void solve(){
    int n;
    cin>>n;
    int secondIdx = ask(1, n);

    if(secondIdx==1 || ask(1, secondIdx)!=secondIdx){
        int low = secondIdx;
        int high = n;
        int ans = -1;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(ask(secondIdx, mid)==secondIdx){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        cout<<"! "<<ans<<endl;
    }
    else{
        int low = 1;
        int high = secondIdx;
        int ans = -1;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(ask(mid, secondIdx)==secondIdx){
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        }
        cout<<"! "<<ans<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    while(t--){
        solve();
    }
}