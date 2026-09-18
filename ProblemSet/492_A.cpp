#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        if (i * (i + 1) * (i + 2) / 6 <= n)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}