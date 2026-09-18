#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
                s1 += a[i];
            else
                s2 -= a[i];
        }
        long long int value = max(s1, s2) - min(s1, s2);
        cout << value << endl;
    }
    return 0;
}