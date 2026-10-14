#include <iostream>
#include <vector>
using namespace std;

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
            prefix_sum[i + 1] = prefix_sum[i] + (a[i] < i + 1 ? 1 : 0);
        long long pairs = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < i + 1 && a[i] > 0)
                pairs += prefix_sum[a[i] - 1];
        }
        cout << pairs << endl;
    }
    return 0;
}