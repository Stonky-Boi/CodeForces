#include <iostream>
using namespace std;

int main()
{
    long int n;
    long long int t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int right = 0, current_sum = 0, max_books = 0;
    for (int left = 0; left < n; left++)
    {
        while (right < n && current_sum + a[right] <= t)
        {
            current_sum += a[right];
            right++;
        }
        max_books = max(max_books, right - left);
        current_sum -= a[left];
    }
    cout << max_books << endl;
    return 0;
}