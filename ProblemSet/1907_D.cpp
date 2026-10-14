#include <iostream>
#include <vector>
using namespace std;

bool valid(vector<int> &left, vector<int> &right, int n, int k)
{
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l = max(l - k, left[i]);
        r = min(r + k, right[i]);
        if (l > r)
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
        int n;
        cin >> n;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
            cin >> left[i] >> right[i];
        int k;
        int l = 0, r = 1e9;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (valid(left, right, n, m))
            {
                k = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << k << endl;
    }
    return 0;
}