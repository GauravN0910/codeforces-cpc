#include<bits/stdc++.h>
using namespace std;

struct segTree {
    int size;
    vector<int> sums;

    void init(int n) {
        size = n;
        sums.resize(4 * n, 0);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if (lx > r || rx < l) {
            return 0;
        }

        if (lx >= l && rx <= r) {
            return sums[x];
        }

        int mid = (lx + rx) / 2;

        int left = sum(l, r, 2 * x + 1, lx, mid);
        int right = sum(l, r, 2 * x + 2, mid + 1, rx);

        return left + right;
    }

    pair<int,int> walk(int sumReq, int sum, int x, int lx, int rx) {
        if(lx == rx) {
            return {sum + sums[x], lx};
        }

        int mid = (lx + rx) / 2;
        if(sums[2 * x + 1] + sum >= sumReq){
            return walk(sumReq, sum, 2*x+1, lx, mid);
        }
        return walk(sumReq, sum + sums[2*x+1], 2*x+2, mid+1, rx);
    }

    void set(int index, int value, int x, int lx, int rx) {
        if (lx == rx) {
            sums[x] += value;
            return;
        }

        int mid = (lx + rx) / 2;
        if (index <= mid) {
            set(index, value, 2*x+1, lx, mid);
        }
        else {
            set(index, value, 2*x+2, mid+1, rx);
        }

        sums[x] = sums[x * 2 + 1] + sums[x * 2 + 2];

        return;
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, size-1);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size - 1);
    }

    pair<int,int> walk(int sumReq) {
        return walk(sumReq, 0, 0, 0, size - 1);
    }
};

void solve(){
    int n; cin >> n;

    vector<pair<int,int>> cities(n);
    for(auto &city : cities){
        cin >> city.first >> city.second;
    }

    map<int,int> reverseMap;

    set<int> set;
    for(auto &city : cities){
        set.insert(city.first);
        set.insert(city.second);
    }

    vector<int> values;
    for(auto &i : set){
        values.push_back(i);
    }

    sort(cities.begin(), cities.end());

    for(int i = 0; i < values.size(); i++) {
        reverseMap[i] = values[i];
    }

    for(auto &city : cities) {
        city.first = lower_bound(values.begin(), values.end(), city.first) - values.begin();
        city.second = lower_bound(values.begin(), values.end(), city.second) - values.begin();
    }

    segTree left, right; 
    left.init(values.size());
    right.init(values.size());

    int ansX = 0, ansY = 0, finalAns = 0, leftSum = 0, rightSum = 0;

    for(int i = 0; i < n; i++) {
        right.set(cities[i].second, 1);
        rightSum++;
    }

    auto checkerFn = [&](int mid) -> pair<int,int> {
        if(min(leftSum, rightSum) < mid / 2){
            return {0, 0};
        }

        int partition = max(left.walk(mid).second, right.walk(mid).second);
        int leftQuery = left.sum(0, partition);
        int rightQuery = right.sum(0, partition);

        if(leftQuery >= mid && leftSum - leftQuery >= mid && 
            rightQuery >= mid && rightSum - rightQuery >= mid) {
            return {1, partition + 1};
        }

        return {0, 0};
    };

    for(int i = 0; i < n; i++) {
        if(i == 0 || (cities[i - 1].first != cities[i].first)) {
            int low = finalAns + 1, high = n / 4, tempAnswer = 0, yCoord = 0;

            while(low <= high) {
                int mid = (low + high) / 2;
                pair<int,int> result = checkerFn(mid);
                if(result.first) {
                    tempAnswer = mid;
                    yCoord = result.second;
                    low = mid + 1;
                }
                else high = mid - 1;
            }

            if(tempAnswer > finalAns) {
                finalAns = tempAnswer;
                ansX = cities[i].first;
                ansY = yCoord;
            }
        }

        rightSum--, leftSum++;
        right.set(cities[i].second, -1);
        left.set(cities[i].second, 1);
    }

    cout<<finalAns<<endl<<reverseMap[ansX]<<" "<<reverseMap[ansY]<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin >> t;

    while(t--) {
        solve();
    }   
}