#include <iostream>
using namespace std;

char upper_to_lower(char c)
{
    int str = (int)c;
    if (str > 64 && str < 91)
        str += 32;
    c = (char)str;
    return c;
}
void compare(string str_1, string str_2)
{
    str_1[0] = upper_to_lower(str_1[0]);
    str_2[0] = upper_to_lower(str_2[0]);
    if (str_1[0] < str_2[0])
        cout << "-1" << endl;
    else if (str_1[0] > str_2[0])
        cout << "1" << endl;
    else if (str_1.size() == 1)
        cout << "0" << endl;
    else
    {
        str_1 = str_1.substr(1);
        str_2 = str_2.substr(1);
        compare(str_1, str_2);
    }
}

int main()
{
    string str_1, str_2;
    cin >> str_1 >> str_2;
    compare(str_1, str_2);
    return 0;
}