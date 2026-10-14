#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool valid(vector<int> &a, int h, int k)
{
    vector<int> b(a.begin(), a.begin() + k);
    sort(b.begin(), b.end(), greater<int>());
    long long sum = 0;
    for (int i = 0; i < k; i += 2)
    {
        sum += b[i];
        if (sum > h)
            return false;
    }
    return true;
}

int main()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int k = 0;
    int l = 0, r = n;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (valid(a, h, m))
        {
            k = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << k << endl;
    return 0;
}