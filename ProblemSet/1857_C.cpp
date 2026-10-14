#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = n * (n - 1) / 2;
        vector<int> b(m);
        for (int &i : b)
            cin >> i;
        sort(b.begin(), b.end());
        vector<int> a;
        a.reserve(n);
        int j = 0, k = n - 1;
        while (k > 0)
        {
            a.push_back(b[j]);
            j += k;
            k--;
        }
        a.push_back(b[m - 1]);
        for (const int &i : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}