#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        bool subsegment_exists = false;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] == k)
            {
                subsegment_exists = true;
                break;
            }
        }
        if (subsegment_exists)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}