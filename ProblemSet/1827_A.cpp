#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        long long ways = 1;
        for (int i = 0; i < n; i++)
        {
            int count = a.end() - upper_bound(a.begin(), a.end(), b[i]);
            int choices = count - i;
            if (choices <= 0)
            {
                ways = 0;
                break;
            }
            ways = (ways * choices) % MOD;
        }
        cout << ways << endl;
    }
    return 0;
}