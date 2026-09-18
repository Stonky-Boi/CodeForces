#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin >> x;
        int y = 9;
        for (int i = 0; i < x.length(); i++)
            if ((x[i] - '0') < y)
                y = x[i] - '0';
        cout << y << endl;
    }
    return 0;
}