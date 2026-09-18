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
        if (n == 1)
            cout << "1" << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                    cout << "-1";
                else
                    cout << ((i == n - 1 && n % 2 == 0) ? 2 : 3);
                if (i < n - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}