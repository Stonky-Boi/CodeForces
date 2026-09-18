#include <iostream>
using namespace std;

int main()
{
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    string s;
    cin >> s;
    int calories = 0;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i] - '0')
        {
        case 1:
            calories += a1;
            break;
        case 2:
            calories += a2;
            break;
        case 3:
            calories += a3;
            break;
        case 4:
            calories += a4;
            break;
        default:
            break;
        }
    }
    cout << calories << endl;
    return 0;
}