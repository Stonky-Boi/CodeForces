#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct element
{
    int index;
    int value;
    int next;

    static bool comp_value(const element &a, const element &b)
    {
        return a.value < b.value;
    }

    static bool comp_index(const element &a, const element &b)
    {
        return a.index < b.index;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<element> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i].index = i;
            cin >> a[i].value;
        }
        sort(a.begin(), a.end(), element::comp_value);
        int prev_next = -1;
        long long prev_sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (prev_next >= i)
                a[i].next = prev_next;
            else
            {
                a[i].next = i;
                long long curr_sum = prev_sum + a[i].value;
                while (a[i].next + 1 < n && curr_sum >= a[a[i].next + 1].value)
                {
                    a[i].next++;
                    curr_sum += a[a[i].next].value;
                }
                prev_sum = curr_sum;
            }
            prev_next = a[i].next;
        }
        sort(a.begin(), a.end(), element::comp_index);
        for (const auto &i : a)
            cout << i.next << ' ';
        cout << endl;
    }
    return 0;
}