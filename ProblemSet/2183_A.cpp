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
        int a[n];
        for (auto &i : a)
            cin >> i;
        if (a[0] == 0 && a[n - 1] == 0)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}