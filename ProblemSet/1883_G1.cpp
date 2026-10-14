#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool valid(vector<int> &a, vector<int> &b, int n, int operations)
{
    for (int i = 0; i < n - operations; i++)
    {
        if (a[i] >= b[operations + i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        a[0] = 1;
        for (int i = 1; i < n; i++)
            cin >> a[i];
        for (int &i : b)
            cin >> i;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int operations;
        int left = 0, right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (valid(a, b, n, mid))
            {
                operations = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        cout << operations << endl;
    }
    return 0;
}