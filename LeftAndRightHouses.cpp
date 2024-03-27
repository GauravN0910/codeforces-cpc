#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int left = 0;
        int right = n;

        int sufZero = 0;
        int sufOne = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                sufZero++;
            }
            else
            {
                sufOne++;
            }
        }

        double mid = (double)n / 2;
        double minDiff = mid;

        int prefZero = 0;
        int prefOne = 0;
        int ans=INT_MAX;
        int leftMin = left / 2;
        int rightMin = right / 2;
        if (left % 2)
        {
            leftMin++;
        }
        if (right % 2)
        {
            rightMin++;
        }
        if (prefZero >= leftMin && sufOne >= rightMin){
            ans = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            left++;
            right--;
            if (s[i - 1] == '0')
            {
                prefZero++;
                sufZero--;
                leftMin = left / 2;
                rightMin = right / 2;
                if (left % 2)
                {
                    leftMin++;
                }
                if (right % 2)
                {
                    rightMin++;
                }
                if (prefZero >= leftMin && sufOne >= rightMin)
                {
                    if ((double)abs(mid - i) < minDiff)
                    {
                        minDiff = (double)abs(mid - i);
                        ans = i;
                    }
                }
            }
            else
            {
                prefOne++;
                sufOne--;
                leftMin = left / 2;
                rightMin = right / 2;
                if (left % 2)
                {
                    leftMin++;
                }
                if (right % 2)
                {
                    rightMin++;
                }
                if (prefZero >= leftMin && sufOne >= rightMin)
                {
                    if ((double)abs(mid - i) < minDiff)
                    {
                        minDiff = (double)abs(mid - i);
                        ans = i;
                    }
                }
            }
        }

        if(ans==INT_MAX){
            ans = n;
        }
        cout << ans << endl;
    }
}