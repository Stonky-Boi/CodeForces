#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        cout << ((n - a - b > 1) || (a == n && b == n) ? "Yes" : "No") << endl;
    }
    return 0;
}