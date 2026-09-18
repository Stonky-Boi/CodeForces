#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long long int a[n], total_area = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            total_area += a[i];
        long long int side_length = sqrt(total_area);
        if (side_length * side_length == total_area)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}