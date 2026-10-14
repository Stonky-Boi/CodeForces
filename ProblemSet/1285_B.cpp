#include <iostream>
#include <vector>
using namespace std;

long long max_subarray(vector<long long> &a, int l, int r)
{
    long long curr_sum = a[l];
    long long max_sum = a[l];
    for (int i = l + 1; i <= r; i++)
    {
        curr_sum = max(a[i], curr_sum + a[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long sum = 0;
        for (long long &i : a)
        {
            cin >> i;
            sum += i;
        }
        long long s1 = max_subarray(a, 0, n - 2);
        long long s2 = max_subarray(a, 1, n - 1);
        cout << (sum > max(s1, s2) ? "YES" : "NO") << endl;
    }
    return 0;
}