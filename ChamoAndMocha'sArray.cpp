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

        if(n==2){
            cout<<*min_element(a.begin(), a.end())<<endl;
        }

        else{
            int ans = INT_MIN;

            for(int i=0;i<n-2;i++){
                vector<int> temp(3);
                for(int j=0;j<3;j++){
                    temp[j] = (a[i+j]);
                }
                sort(temp.begin(), temp.end());
                ans = max(ans, temp[1]);
            }   
            cout<<ans<<endl;
        }
    }
}