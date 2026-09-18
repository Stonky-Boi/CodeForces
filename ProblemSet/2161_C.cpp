#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long x;
        cin >> n >> x;
        vector<long long> a(n);
        for (auto &i : a)
            cin >> i;
        sort(a.begin(), a.end(), greater<>());
        long long s = 0, bonus = 0;
        int l = 0, r = n - 1;
        vector<long long> order;
        while (l <= r)
        {
            if ((s + a[l]) / x > s / x)
            {
                s += a[l];
                order.push_back(a[l]);
                bonus += a[l];
                l++;
            }
            else
            {
                s += a[r];
                order.push_back(a[r]);
                r--;
            }
        }
        cout << bonus << endl;
        for (int i = 0; i < n; i++)
            cout << order[i] << " ";
        cout << endl;
    }
    return 0;
}