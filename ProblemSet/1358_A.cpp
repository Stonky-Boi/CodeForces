#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, lanterns = 0;
        cin >> n >> m;
        if (n % 2 == 0)
            lanterns = (n / 2) * m;
        else if (m % 2 == 0)
            lanterns = (m / 2) * n;
        else
            lanterns = (n / 2) * m + (m / 2) + 1;
        cout << lanterns << endl;
    }
    return 0;
}