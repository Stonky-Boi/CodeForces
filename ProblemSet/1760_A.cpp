#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int medium_number = a + b + c - min(a, min(b, c)) - max(a, max(b, c));
        cout << medium_number << endl;
    }
    return 0;
}