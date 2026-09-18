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
        long int a[n], min = 10000000;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < min)
                min = a[i];
        }
        long int candy = 0;
        for (int i = 0; i < n; i++)
            candy += a[i] - min;
        cout << candy << endl;
    }
    return 0;
}