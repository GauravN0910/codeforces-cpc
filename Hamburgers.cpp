#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    long long nb, ns, nc;
    cin>>nb>>ns>>nc;
    long long pb, ps, pc;
    cin>>pb>>ps>>pc;
    long long money;
    cin>>money;

    long long bunPerBurger = 0;
    long long sausagePerBurger = 0;
    long long cheesePerBurger = 0;

    long long n = s.size();
    for(long long i=0;i<n;i++){
        if(s[i]=='B'){
            bunPerBurger++;
        }
        else if(s[i]=='S'){
            sausagePerBurger++;
        }
        else{
            cheesePerBurger++;
        }
    }


    long long low = 0;
    long long high = 1e15;
    long long ans = 0;

    while(low<=high){
        long long mid = low + (high-low)/2;
        long long x = max(0ll, bunPerBurger*mid - nb)*pb + max(0ll, sausagePerBurger*mid - ns)*ps + max(0ll, cheesePerBurger*mid - nc)*pc;
        if(x<=money){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<ans<<endl;
}