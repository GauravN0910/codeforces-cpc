#include <bits/stdc++.h>
using namespace std;

int invertedPairs(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return 0;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
    }

    int inverted = 0;
    vector<int> x;
    while (!pq.empty())
    {
        auto [val, idx] = pq.top();
        pq.pop();
        int y = lower_bound(x.begin(), x.end(), idx) - x.begin();
        inverted += idx - y;
        x.insert(upper_bound(x.begin(), x.end(), idx), idx);
    }
    return inverted;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = invertedPairs(nums);
    cout << ans;
}