#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        map<int, int> map;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            map[x]++;
        }
        int flag = 0;
        for(auto elem:map){
            if(elem.second>=k){
                flag = 1;
            }
        }

        if(flag == 0){
            cout<<n<<endl;
        }
        else{
            cout<<k-1<<endl;
        }
    }
}