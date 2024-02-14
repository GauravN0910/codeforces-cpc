#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int left, int mid, int right, vector<int> &temp)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int inverted = 0;
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
            inverted += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }

    while (j <= right)
    {
        temp[k++] = nums[j++];
    }

    for (int i = left; i <= right; i++)
    {
        nums[i] = temp[i];
    }
    return inverted;
}

int mergeSort(vector<int> &nums, int left, int right, vector<int> &temp)
{
    int inverted = 0;
    if (right > left)
    {
        int mid = left + (right - left) / 2;
        inverted += mergeSort(nums, left, mid, temp);
        inverted += mergeSort(nums, mid + 1, right, temp);

        inverted += merge(nums, left, mid, right, temp);
    }
    return inverted;
}

int invertedPairs(vector<int> &nums, int n)
{
    vector<int> temp(n);
    return mergeSort(nums, 0, n - 1, temp);
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

    int ans = invertedPairs(nums, n);
    cout << ans << endl;
}
