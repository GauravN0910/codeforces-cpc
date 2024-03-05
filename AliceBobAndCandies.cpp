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
        vector<int> candies(n);
        for (int i = 0; i < n; i++)
        {
            cin >> candies[i];
        }

        int moves = 0;
        int a = 0;
        int b = 0;
        int preva = 0;
        int prevb = 0;
        int flag = 0;

        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            if (flag == 0)
            {
                while (preva <= prevb && left<=right)
                {
                    a += candies[left];
                    preva += candies[left];
                    left++;
                }
                prevb = 0;
                moves++;
                flag = 1;
            }
            else
            {
                while (prevb <= preva && left<=right)
                {
                    b += candies[right];
                    prevb += candies[right];
                    right--;
                }
                preva = 0;
                moves++;
                flag = 0;
            }
        }

        cout << moves << " " << a << " " << b << endl;
    }
}