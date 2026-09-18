#include <iostream>
using namespace std;

int main()
{
    int t, n, f, k, r;
    string a, b;
    cout << "Enter: " << endl;
    cin >> t;
    while (t--)
    {
        cin >> b >> a;
        n = b[0];
        f = b[1];
        k = b[2];
        int c = a[f];
        /*  for (int i = 0; i < t - 1; i++)
         {
             for (int j = 0; j < t - i - 1; j++)
             {
                 if (a[j] < a[j + 1])
                     swap(a[j], a[j + 1]);
             }
         } */
        std::sort(a[0], a[t-1],greater<int>());
        int low = 0, high = t - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] == c)
                r = mid;
            else if (a[mid] < c)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (r <= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}