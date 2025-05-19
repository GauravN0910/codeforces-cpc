#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
long double scale = 1e7;


/*The scale factor is used to handle floating point precision*/
long double dfs(int c, int m, int p, int v){
    long double ans = p/scale;

    if(c>0){
        if(c>v){
            if(m>0){
                ans += (c/scale) * (1 + dfs(c-v, m + v/2, p+v/2, v));
            }
            else{
                ans += (c/scale) * (1 + dfs(c-v, 0, p+v, v));
            }
        }
        else{
            if(m>0){
                ans += (c/scale) * (1 + dfs(0, m + c/2, p+c/2, v));
            }
            else{
                ans += (c/scale) * (1 + dfs(0, 0, p+c, v));
            }
        }
    }

    if(m>0){
        if(m>v){
            if(c>0){
                ans += (m/scale) * (1 + dfs(c + v/2, m-v, p+v/2, v));
            }
            else{
                ans += (m/scale) * (1 + dfs(0, m-v, p+v, v));
            }
        }
        else{
            if(c>0){
                ans += (m/scale) * (1 + dfs(c + m/2, 0, p+m/2, v));
            }
            else{
                ans += (m/scale) * (1 + dfs(0, 0, p+m, v));
            }
        }
    }
    return ans;
}

void solve(){
    long double c, m, p, v;
    cin>>c>>m>>p>>v;
    int cInt = c*scale;
    int mInt = m*scale;
    int pInt = p*scale;
    int vInt = v*scale;
    long double ans = dfs(cInt, mInt, pInt, vInt);
    cout<<fixed<<setprecision(12)<<ans<<endl;
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