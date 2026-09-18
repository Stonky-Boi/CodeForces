#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int first_one = s.find("11");
        int last_zero = s.rfind("00");
        if (first_one != -1 && last_zero != -1 && first_one < last_zero)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}