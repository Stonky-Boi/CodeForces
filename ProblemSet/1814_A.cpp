#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << (n % 2 == 0 || k % 2 == 1 ? "YES" : "NO") << endl;
    }
    return 0;
}