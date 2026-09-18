#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int a, b, value;
        cin >> a >> b;
        value = a ^ b;
        cout << value << endl;
    }
    return 0;
}