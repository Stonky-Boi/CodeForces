#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, m;
        cin >> h >> m;
        int new_year = (24 - h - 1) * 60 + (60 - m);
        cout << new_year << endl;
    }
    return 0;
}