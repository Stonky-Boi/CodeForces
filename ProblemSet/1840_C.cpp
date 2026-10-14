#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        int window = 0;
        long long ways = 0;
        for (int &i : a)
        {
            cin >> i;
            if (i <= q)
                window++;
            else
            {
                if (window >= k)
                {
                    long long size = window - k + 1;
                    ways += size * (size + 1) / 2;
                }
                window = 0;
            }
        }
        if (window >= k)
        {
            long long size = window - k + 1;
            ways += size * (size + 1) / 2;
        }
        cout << ways << endl;
    }
    return 0;
}