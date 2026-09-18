#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possible(int f, const vector<long long> &s, long long available_time)
{
    long long curr_time = 1;
    for (int i = f - 1; i >= 0; i--)
    {
        if (curr_time + s[i] > available_time)
            return false;
        curr_time++;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<long long> s(m);
        for (auto &i : s)
            cin >> i;
        sort(s.begin(), s.end());
        long long available_time = (a < b) ? (b - 1) : (n - b);
        long long left = 0, right = min(m, abs(a - b) - 1);
        long long firecrackers = 0;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            if (possible(mid, s, available_time))
            {
                firecrackers = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        cout << firecrackers << endl;
    }
    return 0;
}