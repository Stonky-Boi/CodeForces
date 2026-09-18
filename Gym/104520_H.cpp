#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    long long int a_new[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a_new[i] = 1LL * a[i] * (i + 1) * (n - i);
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a_new, a_new + n);
    sort(b, b + n, greater<>());
    long long int minimum = 0;
    for (int i = 0; i < n; i++)
        minimum += 1LL * a_new[i] * b[i];
    cout << minimum << endl;
    return 0;
}