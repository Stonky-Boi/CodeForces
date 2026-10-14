#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        k--;
        int spot;
        if (n % 2 == 0)
            spot = k % n + 1;
        else
        {
            int d = n / 2;
            spot = (k + k / d) % n + 1;
        }
        cout << spot << endl;
    }
    return 0;
}