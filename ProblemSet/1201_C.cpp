#include <iostream>
using namespace std;

int main()
{
    long int n;
    long long int k;
    cin >> n >> k;
    long long int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long int low = a[n / 2];
    long long int high = a[n / 2] + k;
    long long int median = low;
    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        long long int operations = 0;
        for (int i = n / 2; i < n; i++)
        {
            if (a[i] < mid)
                operations += (mid - a[i]);
            if (operations > k)
                break;
        }
        if (operations <= k)
        {
            median = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << median << endl;
    return 0;
}