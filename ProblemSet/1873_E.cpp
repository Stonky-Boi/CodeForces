#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, x;
        cin >> n >> x;
        long long int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long int maximum_height = a[0], minimum_height = a[0];
        for (int i = 0; i < n; i++)
        {
            if (a[i] > maximum_height)
                maximum_height = a[i];
            if (a[i] < minimum_height)
                minimum_height = a[i];
        }
        long long int h = minimum_height;
        maximum_height += x;
        while (minimum_height <= maximum_height)
        {
            long long int middle = (minimum_height + maximum_height) / 2;
            long long int water_used = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < middle)
                    water_used += (middle - a[i]);
            }
            if (water_used <= x)
            {
                h = middle;
                minimum_height = middle + 1;
            }
            else
                maximum_height = middle - 1;
        }
        cout << h << endl;
    }
    return 0;
}