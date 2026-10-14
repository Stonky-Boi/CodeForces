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
        vector<vector<int>> a(n);
        int min1 = 1e9, min2 = 1e9;
        long long min_sum = 0;
        for (vector<int> &v : a)
        {
            int m;
            cin >> m;
            v.resize(m);
            for (int &i : v)
                cin >> i;
            sort(v.begin(), v.end());
            min1 = min(min1, v[0]);
            min_sum += v[1];
            min2 = min(min2, v[1]);
        }
        cout << min1 + min_sum - min2 << endl;
    }
    return 0;
}