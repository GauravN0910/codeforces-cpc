#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int total = n+m;
        vector<int> a(total+1), b(total+1);
        for(int i=0;i<=total;i++){
            cin>>a[i];
        }
        for(int i=0;i<=total;i++){
            cin>>b[i];
        }

        int pro = 0;
        int test = 0;
        int betterP = 0;
        long long A = 0; //moreProgrammers (N+1 and M)
        long long B = 0; //moreTesters (N and M+1)
        vector<int> p(total+1), q(total+1);
        for(int i=0;i<=total;i++){
            if(a[i]>b[i]) betterP++;
            if(a[i]>b[i] && pro<=n || m == i-pro){
                pro++;
                p[i] = 1;
                A += a[i];
            }
            else{
                A += b[i];
            }

            if(a[i]<b[i] && test<=m || n == i-test){
                test++;
                q[i] = 1;
                B += b[i];
            }
            else{
                B += a[i];
            }
        }

        for(int i=0;i<=total;i++){
            long long ans = 0;
            if(betterP>n){
                if(p[i]){
                    ans = A - a[i];
                }
                else{
                    ans = B - b[i];
                }
            }
            else{
                if(q[i]){
                    ans = B - b[i];
                }
                else{
                    ans = A - a[i];
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}