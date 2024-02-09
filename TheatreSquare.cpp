#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n, m, a;
    cin >> n >> m >> a;
    unsigned long long ans = ceil((double)m / a) * ceil((double)n / a);
    cout << ans << endl;
}