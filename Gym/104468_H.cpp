#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // TLE on test case 9 without fast IO
    int N;
    cin >> N;
    vector<long long> A(N);
    for (auto &x : A)
        cin >> x;
    vector<int> C(N);
    for (auto &x : C)
        cin >> x;
    map<int, vector<long long>> prefix_by_color;
    for (int i = 0; i < N; i++)
    {
        int color = C[i];
        if (!prefix_by_color.count(color))
            prefix_by_color[color] = {0};
        prefix_by_color[color].push_back(prefix_by_color[color].back() + A[i]);
    }
    long long total_add = 0;
    map<int, long long> excluded_add;
    int Q;
    cin >> Q;
    while (Q--)
    {
        int type, column;
        long long value;
        cin >> type >> column >> value;
        if (type == 1)
        {
            total_add += value;
            excluded_add[column] += value;
        }
        else
        {
            const vector<long long> &prefix = prefix_by_color[column];
            long long color_add = total_add - excluded_add[column];
            int l = 0, r = (int)prefix.size() - 1, prefix_length = 0;
            while (l <= r)
            {
                int m = (l + r) / 2;
                long long sum_m = prefix[m] + color_add * m;
                if (sum_m <= value)
                {
                    prefix_length = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            cout << prefix_length << endl;
        }
    }
    return 0;
}