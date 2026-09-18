#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long int n, q;
    cin >> n >> q;
    long int a[n];
    int frequency[n + 1] = {0};
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        frequency[l - 1] += 1;
        frequency[r] -= 1;
    }
    for (int i = 1; i < n; i++)
        frequency[i] += frequency[i - 1];
    sort(a, a + n, greater<long int>());
    sort(frequency, frequency + n, greater<int>());
    long long int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * 1LL * frequency[i];
    cout << sum << endl;
    return 0;
}