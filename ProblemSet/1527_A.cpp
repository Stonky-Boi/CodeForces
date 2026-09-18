#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long k;
        while (n != 0)
        {
            k = n - 1;
            n = n & (n - 1);
        }
        cout << k << endl;
    }
    return 0;
}