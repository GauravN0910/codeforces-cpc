#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        
        bool flag = false;
        for(int i=0;i<n;i++){
            if(a==sortedA){
                flag = true;
                break;
            }
            int x = a[0];
            a.erase(a.begin());
            a.push_back(x);
        }

        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}