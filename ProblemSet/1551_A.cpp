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
        int c1 = n / 3, c2 = n / 3;
        n = n % 3;
        switch (n)
        {
        case 1:
            c1 += 1;
            c2 += 0;
            break;
        case 2:
            c1 += 0;
            c2 += 1;
            break;
        default:
            break;
        }
        cout << c1 << " " << c2 << endl;
    }
    return 0;
}