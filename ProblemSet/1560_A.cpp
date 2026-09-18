#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int x;
        for (int i = 1; i <= k; i++)
        {
            if (i % 3 == 0 || i % 10 == 3)
                k++;
            else
                x = i;
        }
        cout << x << endl;
    }
    return 0;
}