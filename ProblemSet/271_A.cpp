#include <iostream>
using namespace std;

int main()
{
    int y;
    cin >> y;
    y++;
    string str = to_string(y);
    while (str[0] == str[1] || str[0] == str[2] || str[0] == str[3] || str[1] == str[2] || str[1] == str[3] || str[2] == str[3])
    {
        y++;
        str = to_string(y);
    }
    cout << y << endl;
    return 0;
}