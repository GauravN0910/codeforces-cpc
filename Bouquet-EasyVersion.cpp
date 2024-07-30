#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, m;
        cin>>n>>m;
        
        vector<long long> nums(n);
        for(long long i=0;i<n;i++){
            cin>>nums[i];
        }

        map<long long, long long> count;
        for(long long i=0;i<n;i++){
            count[nums[i]]++;
        }

        long long ans = 0;
        for(auto elem:count){
            long long low = 0;
            long long high = elem.second;
            long long res = 0;
            while(low<=high){
                long long mid = low + (high-low)/2;
                if(mid * elem.first <= m){
                    res += mid * elem.first;
                    long long remainingBudget = m - res;
                    if(count.find(elem.first-1)!=count.end()){
                        res += min(count[elem.first-1] * (elem.first-1), (remainingBudget/elem.first-1) * (elem.first-1));
                    }
                    ans = max(ans, res);
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        
        cout<<ans<<endl;
    }
}






/*
map<long long, long long> map;
    for(int i=0;i<n;i++){
        map[nums[i]]++;
    }

    set<int> x(nums.begin(), nums.end());
    x.insert(1e9+10);

    long long ans = 0;
    for(auto num:x){
        long long numFlowers1 = map[num];
        long long numFlowers2 = map[num-1];
        long long case1 = 0;
        long long case2 = 0;
        long long temp = m;
        case1 += min(numFlowers1 * num, (temp/num)*num);
        temp -= case1;
        case1 += min(numFlowers2 * (num-1), (temp/num)*(num-1));
        
        temp = m;
        case2 += min(numFlowers2 * num-1, (temp/num-1)*(num-1));
        temp -= case2;
        case2 += min(numFlowers1 * num, (temp/num-1)*(num));
        ans = max({ans, case1, case2});

    }
    cout<<ans<<endl;
*/