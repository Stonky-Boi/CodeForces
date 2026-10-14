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
        int moves = 0;
        bool possible = true;
        while (n != 1)
        {
            if (n % 3 != 0)
            {
                possible = false;
                break;
            }
            else if (n % 2 != 0)
            {
                n *= 2;
                moves++;
            }
            else
            {
                n /= 6;
                moves++;
            }
        }
        cout << (possible ? moves : -1) << endl;
    }
    return 0;
}