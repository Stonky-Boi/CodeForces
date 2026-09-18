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
        int floor;
        if (n == 1 || n == 2)
            floor = 1;
        else
            floor = ((n - 3) / x) + 2;
        cout << floor << endl;
    }
    return 0;
}