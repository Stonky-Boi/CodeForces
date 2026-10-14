#include <iostream>
#include <vector>
using namespace std;

void update(vector<int> &prefix_count, int n, int left, int right, int &max_count, int &l, int &r)
{
    int count = prefix_count[right + 1] - prefix_count[left];
    if (count > max_count)
    {
        max_count = count;
        l = left;
        r = n - 1 - right;
    }
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
        vector<int> prefix_count(n + 1, 0); // number of 2s
        for (int i = 0; i < n; i++)
            prefix_count[i + 1] = prefix_count[i] + (abs(a[i]) == 2 ? 1 : 0);
        int max_count = 0;
        int l = n, r = 0;
        int i = 0;
        while (i < n)
        {
            if (a[i] == 0)
            {
                i++;
                continue;
            }
            int j = i;
            int negatives = 0;
            int first = -1, last = -1; // first and last negative
            while (j < n && a[j] != 0)
            {
                if (a[j] < 0)
                {
                    negatives++;
                    if (first == -1)
                        first = j;
                    last = j;
                }
                j++;
            }
            j--;
            if (negatives % 2 == 0)
                update(prefix_count, n, i, j, max_count, l, r);
            else
            {
                update(prefix_count, n, first + 1, j, max_count, l, r);
                update(prefix_count, n, i, last - 1, max_count, l, r);
            }
            i = j + 1;
        }
        cout << l << " " << r << endl;
    }
    return 0;
}