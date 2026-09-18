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
        for (int i = 0; i < n; i++)
        {
            string beat;
            cin >> beat;
            a[i] = beat.find('#') + 1;
        }
        for (int i = 0; i < n; i++)
            cout << a[n - i - 1] << " ";
        cout << endl;
    }
    return 0;
}