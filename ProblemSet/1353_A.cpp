#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, m, value;
        cin >> n >> m;
        if (n == 1)
            value = 0;
        else if (n == 2)
            value = m;
        else
            value = 2 * m;
        cout << value << endl;
    }
    return 0;
}