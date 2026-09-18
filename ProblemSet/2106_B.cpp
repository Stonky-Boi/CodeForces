#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int p[n] = {0};
        if (x == n)
        {
            for (int i = 0; i < n; i++)
                p[i] = i;
        }
        else
        {
            for (int i = 0; i < x; i++)
                p[i] = i;
            for (int i = x; i < n - 1; i++)
                p[i] = i + 1;
            p[n - 1] = x;
        }
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
    }
    return 0;
}