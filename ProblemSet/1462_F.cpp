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
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++)
            cin >> l[i] >> r[i];
        vector<int> left = l;
        vector<int> right = r;
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        int segments = n;
        for (int i = 0; i < n; i++)
        {
            int left_count = lower_bound(right.begin(), right.end(), l[i]) - right.begin();
            int right_count = left.end() - upper_bound(left.begin(), left.end(), r[i]);
            segments = min(segments, left_count + right_count);
        }
        cout << segments << endl;
    }
    return 0;
}