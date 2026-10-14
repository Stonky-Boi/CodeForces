#include <iostream>
#include <vector>
using namespace std;

long long segments(vector<int> &v, int length)
{
    long long count = 0;
    int ones = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
            ones++;
        else
        {
            if (ones >= length)
                count += ones - length + 1;
            ones = 0;
        }
    }
    if (ones >= length)
        count += ones - length + 1;
    return count;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    long long count = 0;
    for (int p = 1; p * p <= k; p++)
    {
        if (k % p != 0)
            continue;
        int q = k / p;
        if (p <= n && q <= m)
        {
            long long x = segments(a, p);
            long long y = segments(b, q);
            count += x * y;
        }
        if (p != q && q <= n && p <= m)
        {
            long long x = segments(a, q);
            long long y = segments(b, p);
            count += x * y;
        }
    }
    cout << count << endl;
    return 0;
}