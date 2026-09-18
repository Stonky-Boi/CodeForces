#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        long long x[n];
        for (auto &i : x)
            cin >> i;
        int tangent_pairs = n - 1;
        long long left = 0, right = LLONG_MAX;
        long long curr = 0;
        int first = 1;
        for (int i = 1; i < n; i++)
        {
            curr = (x[i] - x[i - 1]) - curr;
            if (i % 2 == first % 2)
            {
                right = min(right, curr);
                if (i < n - 1)
                    left = max(left, curr - (x[i + 1] - x[i]));
            }
            else
            {
                left = max(left, -curr);
                if (i < n - 1)
                    right = min(right, (x[i + 1] - x[i]) - curr);
            }
            if (left >= right)
            {
                tangent_pairs--;
                left = 0;
                right = LLONG_MAX;
                curr = 0;
                first = i + 1;
            }
        }
        cout << tangent_pairs << endl;
    }
    return 0;
}