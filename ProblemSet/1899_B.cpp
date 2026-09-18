#include <iostream>
using namespace std;

#define LONG_MAX 9223372036854775807
#define LONG_MIN -9223372036854775808

long long int calculate_difference(long long int n, long long int i, long long int a[])
{
    long long int minimum_sum = LONG_MAX, maximum_sum = LONG_MIN;
    for (long long int j = i; j <= n; j += i)
    {
        long long int current_sum = (j == i) ? a[j - 1] : a[j - 1] - a[j - i - 1];
        minimum_sum = min(minimum_sum, current_sum);
        maximum_sum = max(maximum_sum, current_sum);
    }
    return abs(minimum_sum - maximum_sum);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int a[n], difference = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i)
                a[i] += a[i - 1];
        }
        for (long long int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                difference = max(difference, calculate_difference(n, i, a));
                if (i != n / i)
                    difference = max(difference, calculate_difference(n, n / i, a));
            }
        }
        cout << difference << endl;
    }
    return 0;
}