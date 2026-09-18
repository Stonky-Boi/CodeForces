#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long z;
        cin >> n >> z;
        long long a[n], maximum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            maximum = max(maximum, a[i] | z);
        }
        cout << maximum << endl;
    }
    return 0;
}