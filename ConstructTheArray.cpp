#include<bits/stdc++.h>
using namespace std;

class Compare{
public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        int xA = a.first;
        int yA = a.second;
        int xB = b.first;
        int yB = b.second;
        if((yA-xA)<(yB-xB)){
            return true;
        }
        if((yA-xA)==(yB-xB)){
            return xA>xB;
        }
        return false;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> ans(n+1);
        int opNum = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        pq.push({1, n});

        while(!pq.empty()){
            pair<int, int> topInterval = pq.top();
            pq.pop();

            int l = topInterval.first;
            int r = topInterval.second;


            if((r-l+1)%2){
                int mid = (r+l)/2;
                ans[mid] = opNum;
                opNum++;
                if(mid>l){
                    pq.push({l, mid-1});
                }
                if(mid<r){
                    pq.push({mid+1, r});
                }
            }
            else{
                int mid = (r+l-1)/2;
                ans[mid] = opNum;
                opNum++;
                if(mid>l){
                    pq.push({l, mid-1});
                }
                if(mid<r){
                    pq.push({mid+1, r});
                }
            }
        }

        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}