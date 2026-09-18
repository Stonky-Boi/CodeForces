#include <iostream>
using namespace std;

bool can_fortify(long long target_bases, long long n, long long m, long long k)
{
    long long expansions = target_bases - 1;
    if (expansions == 0)
        return true;
    long long left_space = k - 1;
    long long right_space = n - k;
    long long min_l = max(0LL, expansions - right_space);
    long long max_l = min(expansions, left_space);
    if (min_l > max_l)
        return false;
    long long ideal_l = expansions / 2;
    long long l = ideal_l;
    if (l < min_l)
        l = min_l;
    else if (l > max_l)
        l = max_l;
    long long r = expansions - l;
    long long max_side = max(l, r);
    long long min_side = min(l, r);
    long long days = 2 * max_side + min_side - 1;
    return days <= m;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n >> m >> k;
        long long low = 1, high = n;
        long long bases = 1;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (can_fortify(mid, n, m, k))
            {
                bases = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << bases << endl;
    }
    return 0;
}