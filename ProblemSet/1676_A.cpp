#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if ((int)str[0] + (int)str[1] + (int)str[2] == (int)str[3] + (int)str[4] + (int)str[5])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}