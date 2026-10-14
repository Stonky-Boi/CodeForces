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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        long long sum = 0;
        for (int &i : a)
        {
            cin >> i;
            sum += i;
        }
        sort(a.begin(), a.end());
        long long prev_day = -1;
        long long packs = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            long long curr_day;
            if (x >= sum)
                curr_day = (x - sum) / (i + 1);
            else
                curr_day = -1;
            packs += (i + 1) * (curr_day - prev_day);
            prev_day = curr_day;
            sum -= a[i];
        }
        cout << packs << endl;
    }
    return 0;
}