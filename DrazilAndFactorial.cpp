#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> count(10, 0);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        int v;
        v = c - '0';
        if (v == 2)
            count[2]++;
        else if (v == 3)
            count[3]++;
        else if (v == 4)
            count[2] += 2, count[3]++;
        else if (v == 5)
            count[5]++;
        else if (v == 6)
            count[3]++, count[5]++;
        else if (v == 7)
            count[7]++;
        else if (v == 8)
            count[2] += 3, count[7]++;
        else if (v == 9)
            count[2] += 1, count[3] += 2, count[7]++;
    }

    for (int i = 9; i >= 2; i--)
    {
        while (count[i])
        {
            cout << i;
            count[i]--;
        }
    }
}