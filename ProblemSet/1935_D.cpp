#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> s(n);
        long long even = 0, odd = 0;
        long long sum_count = 0, diff_count = 0;
        for (int &i : s)
        {
            cin >> i;
            sum_count += i / 2 + 1;
            diff_count += c - i + 1;
            if (i % 2 == 0)
                even++;
            else
                odd++;
        }
        long long total = 1ll * (c + 1) * (c + 2) / 2;
        long long intersection = even * (even + 1) / 2 + odd * (odd + 1) / 2;
        long long pairs = total - sum_count - diff_count + intersection;
        cout << pairs << endl;
    }
    return 0;
}