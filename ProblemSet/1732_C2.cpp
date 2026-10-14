#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long get_value(int l, int r, vector<long long> &prefix_sum, vector<long long> &prefix_xor)
{
    long long s = prefix_sum[r] - prefix_sum[l - 1];
    long long x = prefix_xor[r] ^ prefix_xor[l - 1];
    return s - x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<long long> prefix_sum(n + 1, 0), prefix_xor(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix_sum[i + 1] = prefix_sum[i] + a[i];
            prefix_xor[i + 1] = prefix_xor[i] ^ a[i];
        }
        vector<int> nonzero_positions;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
                nonzero_positions.push_back(i + 1);
        }
        while (q--)
        {
            int L, R;
            cin >> L >> R;
            long long target = get_value(L, R, prefix_sum, prefix_xor);
            int left = L;
            int right = R;
            if (target == 0)
            {
                cout << L << " " << L << endl;
                continue;
            }
            auto first = lower_bound(nonzero_positions.begin(), nonzero_positions.end(), L);
            auto last = upper_bound(nonzero_positions.begin(), nonzero_positions.end(), R);
            vector<int> left_positions;
            vector<int> right_positions;
            for (auto it = first; it != last && left_positions.size() < 31; it++)
                left_positions.push_back(*it);
            for (auto it = last; it != first && right_positions.size() < 31;)
            {
                it--;
                right_positions.push_back(*it);
            }
            for (int l : left_positions)
            {
                for (int r : right_positions)
                {
                    if (l > r)
                        continue;
                    if (get_value(l, r, prefix_sum, prefix_xor) == target)
                    {
                        if (r - l < right - left)
                        {
                            left = l;
                            right = r;
                        }
                    }
                }
            }
            cout << left << " " << right << endl;
        }
    }
    return 0;
}