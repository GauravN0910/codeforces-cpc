#include <bits/stdc++.h>
using namespace std;

int uglyNumber(int n)
{
    vector<int> ugly(1, 1);
    int i = 0, j = 0, k = 0;
    while(ugly.size()!=n){
        ugly.push_back(min({ugly[i]*2, ugly[j]*3, ugly[k]*5}));
        if(ugly.back()==ugly[i]*2) i++;
        if(ugly.back()==ugly[j]*3) j++;
        if(ugly.back()==ugly[k]*5) k++;
    }
    return ugly.back();
}

int main()
{
    int n;
    cin >> n;
    int ans = uglyNumber(n);
    cout << ans;
}