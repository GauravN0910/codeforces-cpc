#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> sortedArray = nums;
    sort(sortedArray.begin(), sortedArray.end());

    if (nums == sortedArray)
    {
        cout << "yes" << endl
             << "1 1" << endl;
        return 0;
    }
    int start, end;
    int i = 0;
    while (i < n - 1)
    {
        if (nums[i] < nums[i + 1])
        {
            i++;
        }
        else
        {
            start = i;
            end = i;
            while (nums[i] > nums[i + 1] && i < n - 1)
            {
                i++;
                end++;
            }
            int startCopy = start;
            int endCopy = end;
            while (startCopy < endCopy)
            {
                swap(nums[startCopy], nums[endCopy]);
                startCopy++;
                endCopy--;
            }
            break;
        }
    }

    if (nums != sortedArray)
    {
        cout << "no" << endl;
    }

    else
    {
        cout << "yes" << endl
             << start + 1 << " " << end + 1;
    }
}
