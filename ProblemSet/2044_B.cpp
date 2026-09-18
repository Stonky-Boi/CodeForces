#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] == 'p')
                cout << "q";
            else if (a[i] == 'q')
                cout << "p";
            else
                cout << "w";
        }
        cout << endl;
    }
    return 0;
}