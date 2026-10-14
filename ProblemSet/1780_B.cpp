#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
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
        long long score = 0;
        for (int i = 1; i < n; i++)
            score = max(score, gcd(prefix_sum[i], prefix_sum[n] - prefix_sum[i]));
        cout << score << endl;
    }
    return 0;
}