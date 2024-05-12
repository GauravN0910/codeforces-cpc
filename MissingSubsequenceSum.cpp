#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> ans;

        if(k==1){
            ans.push_back(3);
            for(int i=1;i<22;i++){
                ans.push_back((1<<i));
                if((1<<i)>n||ans.size()==22){
                    break;
                }
            }
        }

        else if(k==2){
            ans.push_back(1);
            ans.push_back(3);
            ans.push_back(6);
            for(int i=2;i<22;i++){
                ans.push_back((1<<i));
                if((1<<i)>n||ans.size()==22){
                    break;
                }
            }
        }


        else{
            int position = log2(k-1);
            for(int i=0;i<position;i++){
                ans.push_back((1<<i));
            }

            ans.push_back((k-1)-(1<<position)+1);
            ans.push_back(k+1);
            position = log2(k+1);
            position++;
            ans.push_back((1<<position)-1);
            for(int i=position;i<22;i++){
                ans.push_back((1<<i));
                if((1<<i)>n||ans.size()==22){
                    break;
                }
            }
        }

        cout<<ans.size()<<endl;
        for(auto num:ans){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}