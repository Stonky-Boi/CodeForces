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
        if (str == "abc" || str == "bac" || str == "acb" || str == "cba")
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}