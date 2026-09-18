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
        int animals = (n / 4) + ((n % 4) / 2);
        cout << animals << endl;
    }
    return 0;
}