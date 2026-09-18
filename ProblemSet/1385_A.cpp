#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int x, y, z;
        cin >> x >> y >> z;
        int maximum = max(x, max(y, z));
        int minimum = min(x, min(y, z));
        int middle = x + y + z - maximum - minimum;
        if (maximum == middle)
        {
            cout << "YES" << endl;
            cout << maximum << " " << minimum << " " << minimum << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}