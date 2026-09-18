#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int rotation = 0;
    int start = int('a');
    for (int i = 0; i < str.length(); i++)
    {
        int end = int(str[i]);
        int difference = abs(start - end);
        if (difference > 13)
            difference = 26 - difference;
        rotation += difference;
        start = end;
    }
    cout << rotation << endl;
    return 0;
}