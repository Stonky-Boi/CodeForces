#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string cards[5];
    bool possible = false;
    for (int i = 0; i < 5; i++)
        cin >> cards[i];
    for (int i = 0; i < 5; i++)
    {
        if (cards[i][0] == str[0] || cards[i][1] == str[1])
            possible = true;
    }
    if (possible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}