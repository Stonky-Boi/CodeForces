#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const long long INF = 4e18;

pair<long long, long long> query(int l, int r, int size, vector<pair<long long, long long>> &seg)
{
    long long min_value = INF;
    long long max_value = -INF;
    l += size;
    r += size;
    while (l < r)
    {
        if (l & 1)
        {
            min_value = min(min_value, seg[l].first);
            max_value = max(max_value, seg[l].second);
            l++;
        }
        if (r & 1)
        {
            r--;
            min_value = min(min_value, seg[r].first);
            max_value = max(max_value, seg[r].second);
        }
        l /= 2;
        r /= 2;
    }
    return {min_value, max_value};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_sum[i + 1] = prefix_sum[i] + a[i];
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[st.top()] <= a[i])
                st.pop();
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && a[st.top()] <= a[i])
                st.pop();
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
        int size = 1;
        while (size < n + 1)
            size *= 2;
        vector<pair<long long, long long>> seg(2 * size, {INF, -INF});
        for (int i = 0; i <= n; i++)
            seg[size + i] = {prefix_sum[i], prefix_sum[i]};
        for (int i = size - 1; i >= 1; i--)
        {
            seg[i].first = min(seg[2 * i].first, seg[2 * i + 1].first);
            seg[i].second = max(seg[2 * i].second, seg[2 * i + 1].second);
        }
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            if (left[i] < i)
            {
                auto [min_value, max_value] = query(left[i], i, size, seg);
                if (min_value < prefix_sum[i])
                {
                    valid = false;
                    break;
                }
            }
            if (i < right[i])
            {
                auto [min_value, max_value] = query(i + 2, right[i] + 2, size, seg);
                if (max_value > prefix_sum[i + 1])
                {
                    valid = false;
                    break;
                }
            }
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}